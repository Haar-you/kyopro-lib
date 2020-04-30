#pragma once
#include <vector>
#include "Mylib/Convolution/fast_zeta_transform_superset.cpp"
#include "Mylib/Convolution/fast_mobius_transform_superset.cpp"

/**
 * @title 添字BitAnd畳み込み
 * @docs convolution_and.md
 */
template <typename T>
std::vector<T> convolution_and(std::vector<T> f, std::vector<T> g){
  f = fast_zeta_transform_superset(f);
  g = fast_zeta_transform_superset(g);
  for(size_t i = 0; i < f.size(); ++i) f[i] *= g[i];
  f = fast_mobius_transform_superset(f);
  return f;
}
