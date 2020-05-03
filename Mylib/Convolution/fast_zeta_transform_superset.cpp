#pragma once
#include <vector>
#include <functional>

/**
 * @title 上位集合に対する高速Zeta変換
 * @docs fast_zeta_transform_superset.md
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