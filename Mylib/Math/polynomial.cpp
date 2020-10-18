#pragma once
#include <vector>
#include <initializer_list>

namespace haar_lib {
  template <typename T, const auto &convolve>
  class polynomial {
    std::vector<T> data_;

  public:
    explicit polynomial(int N): data_(N){}
    polynomial(std::vector<T> data): data_(data){}
    polynomial(std::initializer_list<T> data): data_(data.begin(), data.end()){}

    auto& data(){return data_;}
    const auto& data() const {return data_;}
    int size() const {return data_.size();}

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
  };
}
