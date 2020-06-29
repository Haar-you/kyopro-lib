#pragma once
#include <vector>
#include <cassert>

/**
 * @title Factorial table
 * @docs factorial_table.md
 * @attention 使用前にinit関数を呼び出す
 */
template <typename T> class FactorialTable{
public:
  static std::vector<T> f_table;
  static std::vector<T> if_table;

  static void init(int N){
    f_table.assign(N+1, 1);
    if_table.assign(N+1, 1);
    
    for(int i = 1; i <= N; ++i){
      f_table[i] = f_table[i-1] * i;
    }
    
    if_table[N] = f_table[N].inv();

    for(int i = N-1; i >= 0; --i){
      if_table[i] = if_table[i+1] * (i+1);
    }
  }
  
  static T factorial(int64_t i){
    assert(i < (int)f_table.size());
    return f_table[i];
  }
  
  static T inv_factorial(int64_t i){
    assert(i < (int)if_table.size());
    return if_table[i];
  }

  static T P(int64_t n, int64_t k);
  static T C(int64_t n, int64_t k);
  static T H(int64_t n, int64_t k);
  static T stirling_number(int64_t n, int64_t k);
  static T bell_number(int64_t n, int64_t k);
  static std::vector<T> bernoulli_number(int64_t n);
  static T catalan_number(int64_t n);
};

template <typename T> std::vector<T> FactorialTable<T>::f_table = std::vector<T>();
template <typename T> std::vector<T> FactorialTable<T>::if_table = std::vector<T>();

template <typename T> T FactorialTable<T>::P(int64_t n, int64_t k){
  if(n < k or n < 0 or k < 0) return 0;
  return factorial(n) * inv_factorial(n-k);
}

template <typename T> T FactorialTable<T>::C(int64_t n, int64_t k){
  if(n < k or n < 0 or k < 0) return 0;
  return P(n,k) * inv_factorial(k);
}

template <typename T> T FactorialTable<T>::H(int64_t n, int64_t k){
  if(n == 0 and k == 0) return 1;
  return C(n+k-1, k);
}
