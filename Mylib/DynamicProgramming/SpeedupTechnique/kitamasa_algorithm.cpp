#pragma once
#include <vector>

/**
 * @title Kitamasa法
 * @docs kitamasa_algorithm.md
 */
template <typename T> struct KitamasaAlgorithm{
  int size;
  std::vector<T> initial_values, coeff;

  KitamasaAlgorithm(int size, const std::vector<T> &initial_values, const std::vector<T> &coeff):
    size(size), initial_values(initial_values), coeff(coeff){}

  inline std::vector<T> inc(const std::vector<T> &a) const {
    std::vector<T> ret(size);

    for(int i = 0; i < size; ++i) ret[i] += a[size-1] * coeff[i];
    for(int i = 1; i < size; ++i) ret[i] += a[i-1]; 

    return ret;
  }
  
  inline std::vector<T> dbl(const std::vector<T> &a) const {
    std::vector<T> ret(size), b(a);
    
    for(int j = 0; j < size; ++j){
      for(int i = 0; i < size; ++i){
        ret[i] += a[j] * b[i];
      }

      b = inc(b);
    }
    
    return ret;
  }
  
  inline T calc(const std::vector<T> &v) const {
    T ret = 0;
    for(int i = 0; i < size; ++i) ret += v[i] * initial_values[i];
    return ret;
  }

  inline std::vector<T> get(int64_t index) const {
    std::vector<T> ret(size);
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

  inline T operator[](int64_t index) const {
    if(index < size) return initial_values[index];
    return calc(get(index));
  }
};
