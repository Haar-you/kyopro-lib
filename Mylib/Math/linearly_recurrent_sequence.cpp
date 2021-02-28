#pragma once
#include <cassert>
#include <vector>
#include <cstdint>

namespace haar_lib {
  template <typename T, auto &convolve>
  T linearly_recurrent_sequence(const std::vector<T> &a, const std::vector<T> &c, int64_t k){
    assert(a.size() == c.size());

    const int d = a.size();

    std::vector<T> Q(d + 1);
    Q[0] = 1;
    for(int i = 0; i < d; ++i) Q[d - i] = -c[i];

    std::vector<T> P = convolve(a, Q);
    P.resize(d);

    while(k > 0){
      auto q = Q;
      for(size_t i = 1; i < q.size(); i += 2) q[i] = -q[i];
      auto U = convolve(P, q);
      auto A = convolve(Q, q);

      if(k % 2 == 0){
        for(int i = 0; i < d; ++i) P[i] = i * 2 < (int)U.size() ? U[i * 2] : 0;
      }else{
        for(int i = 0; i < d; ++i) P[i] = i * 2 + 1 < (int)U.size() ? U[i * 2 + 1] : 0;
      }

      for(int i = 0; i <= d; ++i) Q[i] = i * 2 < (int)A.size() ? A[i * 2] : 0;

      k >>= 1;
    }

    return P[0];
  }
}
