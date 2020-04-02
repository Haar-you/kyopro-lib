#pragma once
#include <vector>
#include <functional>

/**
 * @see https://atcoder.jp/contests/arc100/submissions/4581560 (演算がやや特殊)
 * @note f(S) = ∑_{T⊆S} g(T)
 */
template <typename T, typename Func = std::plus<T>>
std::vector<T> fast_zeta_transform_subset(std::vector<T> f, const Func &op = std::plus<T>()){
  for(int i = 0; (1<<i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(j & (1<<i)) f[j] = op(f[j], f[j ^ (1<<i)]);
    }
  }
  return f;
}