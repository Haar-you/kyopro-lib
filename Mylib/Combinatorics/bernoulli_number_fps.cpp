#pragma once

namespace haar_lib {
  template <typename Fps, const auto &ft>
  Fps bernoulli_number_fps(int N) {
    Fps x(N + 1);

    for (int i = 0; i <= N; ++i) x[i] = ft.inv_factorial(i + 1);
    x = x.inv();

    for (int i = 0; i <= N; ++i) x[i] *= ft.factorial(i);

    return x;
  }
}  // namespace haar_lib
