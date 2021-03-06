#pragma once
#include <algorithm>
#include <optional>

namespace haar_lib {
  template <typename T>
  struct min_monoid {
    using value_type = std::optional<T>;

    value_type operator()() const { return {}; }
    value_type operator()(const value_type &a, const value_type &b) const {
      if (not a) return b;
      if (not b) return a;
      return {std::min(*a, *b)};
    }
  };
}  // namespace haar_lib
