#pragma once
#include <algorithm>
#include <limits>

namespace haar_lib {
  template <typename T>
  struct bounded_min_monoid {
    using value_type = T;

    value_type operator()() const { return std::numeric_limits<T>::max(); }
    value_type operator()(const value_type &a, const value_type &b) const {
      return std::min(a, b);
    }
  };
}  // namespace haar_lib
