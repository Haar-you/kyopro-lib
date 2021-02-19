#pragma once
#include <vector>
#include <initializer_list>
#include <algorithm>

namespace haar_lib {
  template <typename T, const auto &convolve>
  class polynomial {
  public:
    using value_type = T;

  private:
    std::vector<T> data_;

  public:
    explicit polynomial(int N): data_(N){}
    polynomial(std::vector<T> data): data_(data){}
    polynomial(std::initializer_list<T> data): data_(data.begin(), data.end()){}

    auto& data(){return data_;}
    const auto& data() const {return data_;}
    size_t size() const {return data_.size();}
    auto begin(){return data_.begin();}
    auto end(){return data_.end();}

    const auto& operator[](size_t i) const {return data_[i];}
    auto& operator[](size_t i){return data_[i];}

    auto get(int n) const {
      return polynomial(std::vector(data_.begin(), data_.begin() + std::min<int>(n, data_.size())));
    }

    int shrink(){
      while(not data_.empty() and data_.back() == 0){
        data_.pop_back();
      }
      return data_.size();
    }

    auto& operator+=(const polynomial &that){
      if(data_.size() < that.data_.size()) data_.resize(that.data_.size());
      for(size_t i = 0; i < that.data_.size(); ++i) data_[i] += that.data_[i];
      return *this;
    }

    auto& operator-=(const polynomial &that){
      if(data_.size() < that.data_.size()) data_.resize(that.data_.size());
      for(size_t i = 0; i < that.data_.size(); ++i) data_[i] -= that.data_[i];
      return *this;
    }

    auto& operator*=(T k){
      for(auto &x : data_) x *= k;
      return *this;
    }

    auto& operator/=(T k){
      for(auto &x : data_) x /= k;
      return *this;
    }

    auto& operator*=(const polynomial &that){
      const int k = data_.size() + that.data_.size() - 1;
      data_ = convolve(data_, that.data_);
      data_.resize(k);
      return *this;
    }

    auto operator+(const polynomial &that) const {
      return polynomial(*this) += that;
    }

    auto operator-(const polynomial &that) const {
      return polynomial(*this) -= that;
    }

    auto operator*(T k) const {
      return polynomial(*this) *= k;
    }

    auto operator/(T k) const {
      return polynomial(*this) /= k;
    }

    auto operator*(const polynomial &that) const {
      return polynomial(*this) *= that;
    }

    auto differentiate() const {
      polynomial ret((int)data_.size() - 1);
      for(int i = 0; i < (int)ret.data_.size(); ++i){
        ret.data_[i] = data_[i + 1] * (i + 1);
      }
      return ret;
    }

    auto integrate() const {
      polynomial ret((int)data_.size() + 1);
      for(int i = 1; i < (int)ret.data_.size(); ++i){
        ret.data_[i] = data_[i - 1] / i;
      }

      return ret;
    }

    auto integrate(T lb, T ub) const {
      T ret = 0, x1 = 1, x2 = 1;
      for(int i = 0; i < (int)data_.size(); ++i){
        x1 *= lb;
        x2 *= ub;
        ret += data_[i] / (i + 1) * (x2 - x1);
      }

      return ret;
    }

    auto shift(int k) const {
      polynomial ret((int)data_.size() + k);
      for(int i = 0; i < (int)data_.size(); ++i){
        ret.data_[i + k] = data_[i];
      }

      return ret;
    }

    auto square() const {
      const int k = data_.size() * 2 - 1;
      auto ret = convolve(data_, data_, true);
      ret.resize(k);
      return polynomial(ret);
    }

    auto inv(int n) const {
      polynomial ret({data_[0].inv()});
      int t = 1;

      while(t <= n * 2){
        ret = ret * T(2) - ret.square().get(t) * (*this).get(t);
        if((int)ret.data_.size() > t) ret.data_.resize(t);
        t *= 2;
      }

      return ret;
    }

    std::pair<polynomial, polynomial> divmod(const polynomial &that) const {
      if(data_.size() < that.size()) return {{0}, *this};

      const int m = data_.size() - that.size();

      auto g = *this;
      std::reverse(g.begin(), g.end());

      auto f = that;
      const int d = (int)that.size() - 1;
      std::reverse(f.begin(), f.end());

      f = f.inv(m);

      f.data_.resize(m + 1);

      auto q = f * g;
      q.data_.resize(m + 1);

      std::reverse(q.begin(), q.end());

      auto r = (*this) - that * q;
      r.data_.resize(d);

      r.shrink();
      q.shrink();

      return {q, r};
    }

    auto& operator/=(const polynomial &that){
      *this = divmod(that).first;
      return *this;
    }

    auto& operator%=(const polynomial &that){
      *this = divmod(that).second;
      return *this;
    }

    auto operator/(const polynomial &that) const {
      return polynomial(*this) /= that;
    }

    auto operator%(const polynomial &that) const {
      return polynomial(*this) %= that;
    }
  };
}
