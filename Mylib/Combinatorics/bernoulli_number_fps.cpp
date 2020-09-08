#pragma once

/**
 * @title Bernoulli number (FPS)
 * @docs bernoulli_number_fps.md
 */
namespace haar_lib {
  template <typename Fps, typename Ft>
  auto bernoulli_number_fps(int N, const Ft &ft){
    Fps x(N + 1);

    for(int i = 0; i <= N; ++i) x[i] = ft.inv_factorial(i + 1);
    x = x.inv();

    for(int i = 0; i <= N; ++i) x[i] *= ft.factorial(i);

    return x;
  }
}
