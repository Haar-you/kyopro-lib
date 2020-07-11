#pragma once

/**
 * @docs product.md
 */
template <typename T>
struct ProductMonoid{
  using value_type = T;
  value_type id() const {return 1;}
  value_type op(value_type a, value_type b) const {return a * b;}
};
