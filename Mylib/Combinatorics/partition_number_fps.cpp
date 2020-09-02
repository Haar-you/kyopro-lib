#pragma once
#include <vector>
#include <cmath>

/**
 * @title Partition number (FPS)
 * @docs partition_number_fps.cpp
 */
template <typename Fps>
auto partition_number(int N){
  using T = typename Fps::value_type;

  std::vector<T> f(N + 1);
  f[0] = 1;

  {
    const int M = (sqrt(1 + 24 * N) - 1) / 6;
    for(int i = 1; i <= M; ++i){
      f[i * (3 * i + 1) / 2] += (i % 2 == 0 ? 1 : -1);
    }
  }

  {
    const int M = (sqrt(1 + 24 * N) + 1) / 6;
    for(int i = 1; i <= M; ++i){
      f[i * (3 * i - 1) / 2] += (i % 2 == 0 ? 1 : -1);
    }
  }

  Fps ret(f);
  ret = ret.inv();

  return ret;
}
