#pragma once
#include <utility>
#include <optional>

namespace haar_lib {
  template <typename M>
  std::optional<M> inverse_matrix(M m){
    using T = typename M::value_type;
    const int N = m.size();
    M ret = M::unit();

    for(int i = 0; i < N; ++i){
      int p = i;
      for(int j = i; j < N; ++j){
        if(m[i][j] != 0){
          p = j;
          break;
        }
      }

      std::swap(m[i], m[p]);
      std::swap(ret[i], ret[p]);

      {
        T d = m[i][i];

        if(d == 0) return std::nullopt;

        for(int j = 0; j < N; ++j){
          m[i][j] /= d;
          ret[i][j] /= d;
        }
      }

      for(int j = 0; j < N; ++j){
        if(i == j) continue;
        T d = m[j][i] / m[i][i];
        for(int k = 0; k < N; ++k){
          m[j][k] -= m[i][k] * d;
          ret[j][k] -= ret[i][k] * d;
        }
      }
    }

    return ret;
  }
}
