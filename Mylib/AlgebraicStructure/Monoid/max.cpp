#pragma once
#include <algorithm>
#include <optional>

/**
 * @title Max monoid
 * @docs max.md
 */
template <typename T>
struct MaxMonoid {
  using value_type = std::optional<T>;

  value_type operator()() const {return {};}
  value_type operator()(const value_type &a, const value_type &b) const {
    if(not a) return b;
    if(not b) return a;
    return {std::max(*a, *b)};
  }
};
