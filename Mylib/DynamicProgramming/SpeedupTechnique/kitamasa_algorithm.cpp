#pragma once
#include <vector>
#include <cstdint>

namespace haar_lib {
  template <typename T>
  class kitamasa_algorithm {
    int size_;
    std::vector<T> initial_values_, coeff_;

  public:
    kitamasa_algorithm(){}
    kitamasa_algorithm(int size, const std::vector<T> &initial_values, const std::vector<T> &coeff):
      size_(size), initial_values_(initial_values), coeff_(coeff){}

    std::vector<T> inc(const std::vector<T> &a) const {
      std::vector<T> ret(size_);

      for(int i = 0; i < size_; ++i) ret[i] += a[size_ - 1] * coeff_[i];
      for(int i = 1; i < size_; ++i) ret[i] += a[i - 1];

      return ret;
    }

    std::vector<T> dbl(const std::vector<T> &a) const {
      std::vector<T> ret(size_), b(a);

      for(int j = 0; j < size_; ++j){
        for(int i = 0; i < size_; ++i){
          ret[i] += a[j] * b[i];
        }

        b = inc(b);
      }

      return ret;
    }

    T eval(const std::vector<T> &v) const {
      T ret = 0;
      for(int i = 0; i < size_; ++i) ret += v[i] * initial_values_[i];
      return ret;
    }

    std::vector<T> get(int64_t index) const {
      std::vector<T> ret(size_);
      ret[0] = 1;

      bool check = false;
      for(int i = 63; i >= 0; --i){
        if(check) ret = dbl(ret);

        if(index & (1LL << i)){
          ret = inc(ret);
          check = true;
        }
      }

      return ret;
    }

    T operator[](int64_t index) const {
      if(index < size_) return initial_values_[index];
      return eval(get(index));
    }
  };
}
