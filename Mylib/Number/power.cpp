#pragma once
#include <functional>

/**
 * @title Binary exponentiation
 * @docs power.md
 */
template <typename T>
T power(T n, int64_t p, const T &e, const std::function<T(T, T)> &f){
  T ret = e;

  while(p > 0){
    if(p & 1) ret = f(ret, n);
    n = f(n, n);
    p >>= 1;
  }

  return ret;
}
