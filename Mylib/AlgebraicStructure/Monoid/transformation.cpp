#pragma once
#include <array>

namespace haar_lib {
  template <size_t N>
  struct transformation_monoid {
    using value_type = std::array<int, N>;

    value_type operator()() const {
      value_type ret;
      for (int i = 0; i < (int) N; ++i) ret[i] = i;
      return ret;
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      value_type ret;
      for (int i = 0; i < (int) N; ++i) ret[i] = a[b[i]];
      return ret;
    }
  };
}  // namespace haar_lib
