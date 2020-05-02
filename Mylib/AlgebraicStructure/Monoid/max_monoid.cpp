#pragma once
#include <algorithm>

/**
 * @docs max_monoid.md
 */
template <typename T>
struct MaxMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return std::numeric_limits<T>::lowest();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::max(a, b);}
};
