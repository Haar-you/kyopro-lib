#pragma once
#include <algorithm>
#include <optional>

namespace haar_lib {
  template <typename T>
  struct min_add_semiring {
    using value_type = std::optional<T>;

    value_type id_add() const { return std::nullopt; }
    value_type id_mul() const { return 0; }

    value_type add(const value_type &a, const value_type &b) const {
      if (not a) return b;
      if (not b) return a;
      return {std::min(*a, *b)};
    }
    value_type mul(const value_type &a, const value_type &b) const {
      if (not a or not b) return {};
      return {*a + *b};
    }
  };
}  // namespace haar_lib
