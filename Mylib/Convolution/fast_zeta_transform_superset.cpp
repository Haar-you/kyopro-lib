#pragma once
#include <vector>
#include <functional>

/**
 * @title 上位集合に対する高速Zeta変換
 * @see https://codeforces.com/contest/1208/submission/59501702 (最大値2つを保持)
 * @note f(S) = ∑_{S⊆T} g(T)
 */
template <typename T, typename Func = std::plus<T>>
std::vector<T> fast_zeta_transform_superset(std::vector<T> f, const Func &op = std::plus<T>()){
  for(int i = 0; (1<<i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(!(j & (1<<i))) f[j] = op(f[j], f[j ^ (1<<i)]);
    }
  }
  return f;
}
