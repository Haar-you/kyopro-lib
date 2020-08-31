#pragma once

#include <functional>
#include <vector>
#include <initializer_list>

/**
 * @title Formal power series
 * @docs formal_power_series.md
 */
template <typename T>
struct FormalPowerSeries{
  using value_type = T;
  
  static std::function<std::vector<T>(std::vector<T>, std::vector<T>)> convolve;
  static std::function<std::optional<T>(T)> get_sqrt;

  std::vector<T> data;

  FormalPowerSeries(const std::vector<T> &data): data(data){}
  FormalPowerSeries(std::initializer_list<T> init): data(init.begin(), init.end()){}
  FormalPowerSeries(int N): data(N){}
  
  int size() const {
    return data.size();
  }

  const T& operator[](int i) const {
    return data[i];
  }

  T& operator[](int i){
    return data[i];
  }

  auto begin() {return data.begin();}
  auto end() {return data.end();}

  void resize(int n){
    data.resize(n);
  }
  
  auto operator+(const FormalPowerSeries &rhs) const {
    std::vector<T> ret(data);
    ret.resize(rhs.size());
    for(int i = 0; i < (int)rhs.size(); ++i) ret[i] += rhs[i];
    return FormalPowerSeries(ret);
  }

  auto operator-(const FormalPowerSeries &rhs) const {
    std::vector<T> ret(data);
    ret.resize(rhs.size());
    for(int i = 0; i < (int)rhs.size(); ++i) ret[i] -= rhs[i];
    return FormalPowerSeries(ret);
  }

  auto operator*(const FormalPowerSeries &rhs) const {
    auto ret = convolve(data, rhs.data);
    return FormalPowerSeries(ret);
  }

  auto operator*(T b) const {
    std::vector<T> ret(data);
    for(auto &x : ret) x *= b;
    return FormalPowerSeries(ret);
  }

  auto differentiate() const {
    const int n = data.size();
    std::vector<T> ret(n-1);
    for(int i = 0; i < n-1; ++i){
      ret[i] = data[i+1] * (i + 1);
    }
    
    return FormalPowerSeries(ret);
  }

  auto integrate() const {
    const int n = data.size();
    std::vector<T> ret(n+1);
    for(int i = 0; i < n; ++i){
      ret[i+1] = data[i] / (i + 1);
    }

    return FormalPowerSeries(ret);
  }

  auto inv() const {
    assert(data[0] != 0);
    const int n = data.size();
    
    int t = 1;
    std::vector<T> ret = {data[0].inv()};
    ret.reserve(n * 2);
    
    while(t <= n * 2){
      std::vector<T> c(data.begin(), data.begin() + std::min(t, n));
      c = convolve(c, convolve(ret, ret));

      c.resize(t);
      ret.resize(t);

      for(int i = 0; i < t; ++i){
        ret[i] = ret[i] * 2 - c[i];
      }
      
      t <<= 1;
    }
    
    ret.resize(n);

    return FormalPowerSeries(ret);
  }

  auto log() const {
    assert(data[0] == 1);
    const int n = data.size();
    auto ret = (differentiate() * inv()).integrate();
    ret.resize(n);
    return ret;
  }

  auto exp() const {
    const int n = data.size();

    int t = 1;
    FormalPowerSeries b({1});

    while(t <= n * 2){
      t <<= 1;
      auto temp = b.log();
      temp.resize(t);

      for(int i = 0; i < t; ++i) temp[i] = -temp[i];
      temp[0] += 1;
      for(int i = 0; i < std::min(t, n); ++i) temp[i] += data[i];
      
      b = b * temp;
      b.resize(t);
    }
    
    b.resize(n);

    return b;
  }


  auto shift(int64_t k) const {
    const int64_t n = data.size();
    FormalPowerSeries ret(n);

    if(k >= 0){
      for(int64_t i = k; i < n; ++i){
        ret[i] = data[i - k];
      }
    }else{
      for(int64_t i = 0; i < n + k; ++i){
        ret[i] = data[i - k];
      }
    }

    return ret;
  }

  
  auto power(int64_t M) const {
    assert(M >= 0);
    
    const int n = data.size();
    int k = 0;
    for(; k < n; ++k){
      if(data[k] != 0){
        break;
      }
    }

    if(k >= n) return *this;

    T a = data[k];

    FormalPowerSeries ret = *this;
    ret = (ret.shift(-k)) * a.inv();
    ret = (ret.log() * (T)M).exp();
    ret = (ret * a.power(M)).shift(M * k);
    
    return ret;
  }

  std::optional<FormalPowerSeries> sqrt() const {
    const int n = data.size();
    int k = 0;
    for(; k < n; ++k) if(data[k] != 0) break;

    if(k >= n) return *this;
    if(k % 2 != 0) return {};

    int t = 1;
    auto x = get_sqrt(data[k]);

    if(not x) return {};

    const int m = n - k;

    auto it = data.begin() + k;
    FormalPowerSeries ret({*x});

    while(t <= m * 2){
      FormalPowerSeries f(std::vector(it, it + std::min(t, m)));
      ret.resize(t);
      f.resize(t);
      ret = (ret + f * ret.inv()) * T(2).inv();
      t <<= 1;
    }

    ret.resize(n);
    ret = ret.shift(k / 2);

    return ret;
  }
};


template <typename T>
std::function<std::vector<T>(std::vector<T>, std::vector<T>)> FormalPowerSeries<T>::convolve;

template <typename T>
std::function<std::optional<T>(T)> FormalPowerSeries<T>::get_sqrt;
