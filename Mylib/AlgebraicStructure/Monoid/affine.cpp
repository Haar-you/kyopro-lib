#pragma once
#include <utility>

/**
 * @docs affine.md
 */
template <typename T>
struct AffineMonoid{
  using value_type = std::pair<T, T>;
  static value_type id(){return std::make_pair(1, 0);}
  static value_type op(const value_type &a, const value_type &b){return std::make_pair(a.first * b.first, a.first * b.second + a.second);}
};
