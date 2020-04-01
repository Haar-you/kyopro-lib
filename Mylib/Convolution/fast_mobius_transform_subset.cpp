#pragma once
#include <vector>
#include <functional>

/**
 * @see https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2446 (包除原理への応用)
 * @note f(S) = ∑_{T⊆S} g(T) * (-1)^(|S|-|T|)
 */
template <typename T, typename Func = std::minus<T>>
std::vector<T> fast_mobius_transform_subset(std::vector<T> f, const Func &op = std::minus<T>()){
  for(int i = 0; (1<<i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(j & (1<<i)) f[j] = op(f[j], f[j ^ (1<<i)]);
    }
  }
  return f;
}
