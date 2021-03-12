#pragma once
#include <vector>
#include "Mylib/Number/Prime/primitive_root.cpp"

namespace haar_lib {
  template <typename T, const auto &convolve>
  std::vector<T> convolution_multiply(const std::vector<T> &A, const std::vector<T> &B, int P){
    const int p_root = primitive_root(P);

    std::vector<int> index(P);

    {
      int64_t s = 1;

      for(int i = 0; i < P; ++i){
        index[s] = i;
        s *= p_root;
        if(s >= P) s %= P;
      }
    }

    std::vector<T> a(P), b(P);
    for(int i = 0; i < (int)A.size(); ++i) a[index[i % P]] = A[i];
    for(int i = 0; i < (int)B.size(); ++i) b[index[i % P]] = B[i];

    auto c = convolve(a, b);
    std::vector<T> ret(P);

    {
      int64_t s = 1;

      for(auto x : c){
        ret[s] += x;
        s *= p_root;
        if(s >= P) s %= P;
      }
    }

    return ret;
  }
};
