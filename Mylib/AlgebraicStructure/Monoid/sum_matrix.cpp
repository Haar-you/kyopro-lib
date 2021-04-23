#pragma once

namespace haar_lib {
  template <typename T>
  struct sum_matrix_monoid {
    using value_type = T;
    value_type operator()() const { return T(); }
    value_type operator()(const value_type &a, const value_type &b) const { return a + b; }
  };
}  // namespace haar_lib
