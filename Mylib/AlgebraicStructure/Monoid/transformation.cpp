#pragma once
#include <array>

/**
 * @title Transformation monoid
 * @docs transformation.md
 */
template <size_t N>
struct TransformationMonoid {
  using value_type = std::array<int, N>;

  value_type operator()() const {
    value_type ret;
    for(int i = 0; i < (int)N; ++i) ret[i] = i;
    return ret;
  }

  value_type operator()(const value_type &a, const value_type &b) const {
    value_type ret;
    for(int i = 0; i < (int)N; ++i) ret[i] = a[b[i]];
    return ret;
  }
};
