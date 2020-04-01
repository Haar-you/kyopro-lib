#pragma once
#include <vector>
#include "Mylib/Convolution/fast_zeta_transform_subset.cpp"
#include "Mylib/Convolution/fast_mobius_transform_subset.cpp"

/**
 * @note h_k = ∑_{k=i∪j} f(i) * g(j)
 * @see https://csacademy.com/contest/archive/task/maxor/
 */
template <typename T>
std::vector<T> convolution_or(std::vector<T> f, std::vector<T> g){
  f = fast_zeta_transform_subset(f);
  g = fast_zeta_transform_subset(g);
  for(size_t i = 0; i < f.size(); ++i) f[i] *= g[i];
  f = fast_mobius_transform_subset(f);
  return f;
}

