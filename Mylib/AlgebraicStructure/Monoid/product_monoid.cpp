#pragma once

/**
 * @docs product_monoid.md
 */
template <typename T>
struct ProductMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 1;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a * b;}
};
