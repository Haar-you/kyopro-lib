#pragma once
#include <vector>
#include "Mylib/Convolution/fast_zeta_transform_subset.cpp"
#include "Mylib/Convolution/fast_mobius_transform_subset.cpp"

/**
 * @title 添字BitOr畳み込み
 * @docs convolution_or.md
 */
template <typename T>
std::vector<T> convolution_or(std::vector<T> f, std::vector<T> g){
  f = fast_zeta_transform_subset(f);
  g = fast_zeta_transform_subset(g);
  for(size_t i = 0; i < f.size(); ++i) f[i] *= g[i];
  f = fast_mobius_transform_subset(f);
  return f;
}
