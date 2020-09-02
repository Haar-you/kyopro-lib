#pragma once
#include <vector>

/**
 * @title Subset sum problem (Count, FPS)
 * @docs subset_sum_count_fps.md
 */
template <typename Fps>
auto subset_sum_count_fps(std::vector<int> s, int t){
  using T = typename Fps::value_type;

  std::vector<int> c(t + 1);
  for(int i : s) c[i] += 1;

  Fps ret(t + 1);

  for(int i = 1; i <= t; ++i){
    if(c[i] == 0) continue;

    for(int j = 1; j * i <= t; ++j){
      const int k = j * i;
      const T x = (j % 2 == 1 ? 1 : -1) * i * ((T)k).inv();
      ret[k] += x * c[i];
    }
  }

  ret = ret.exp();

  return ret;
}
