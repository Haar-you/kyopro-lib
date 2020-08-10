#pragma once
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Convolution/formal_power_series.cpp"

/**
 * @title Bernoulli number (FPS)
 * @docs bernoulli_number_fps.md
 */
template <typename Fps, typename Ft>
auto bernoulli_number_fps(int N){
  Fps x(N + 1);

  for(int i = 0; i <= N; ++i) x[i] = Ft::inv_factorial(i + 1);
  x = x.inv();

  for(int i = 0; i <= N; ++i) x[i] *= Ft::factorial(i);

  return x;
}
