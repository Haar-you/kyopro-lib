#pragma once
#include <vector>
#include <functional>
#include <cassert>

namespace haar_lib {
  template <typename T, typename Func = std::plus<T>>
  std::vector<T> fast_zeta_transform_superset(std::vector<T> f, const Func &op = std::plus<T>()){
    const int N = f.size();
    assert((N & (N - 1)) == 0 && "N must be a power of 2");
    for(int i = 1; i < N; i <<= 1){
      for(int j = 0; j < N; ++j){
        if(not (j & i)) f[j] = op(f[j], f[j ^ i]);
      }
    }
    return f;
  }
}
