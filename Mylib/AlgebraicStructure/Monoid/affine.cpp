#pragma once
#include <utility>

/**
 * @docs affine.md
 */
template <typename T>
struct AffineMonoid{
  using value_type = std::pair<T, T>;
  value_type id() const {return std::make_pair(1, 0);}
  value_type op(const value_type &a, const value_type &b) const {
    return std::make_pair(a.first * b.first, a.first * b.second + a.second);
  }
};
