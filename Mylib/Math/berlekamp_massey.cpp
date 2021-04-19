#pragma once
#include <vector>

template <typename T>
std::vector<T> berlekamp_massey(const std::vector<T> &s){
  const int N = s.size();

  std::vector<T> C = {1}, B = {1};
  int L = 0, m = 1;
  T b = 1;

  for(int n = 0; n < N; ++n){
    T d = s[n];
    for(size_t i = 1; i < C.size(); ++i) d += C[i] * s[n - i];

    if(d == 0){
      m += 1;
    }else if(2 * L <= n){
      auto temp = C;
      if(C.size() < B.size() + m) C.resize(B.size() + m);
      const T t = d / b;
      for(int i = 0; i < (int)B.size(); ++i) C[i + m] -= t * B[i];
      L = n + 1 - L;
      B = temp;
      b = d;
      m = 1;
    }else{
      if(C.size() < B.size() + m) C.resize(B.size() + m);
      const T t = d / b;
      for(int i = 0; i < (int)B.size(); ++i) C[i + m] -= t * B[i];
      m += 1;
    }
  }

  std::vector<T> ret(L);
  for(int i = 0; i < L; ++i) ret[i] = -C[i + 1];

  return ret;
}
