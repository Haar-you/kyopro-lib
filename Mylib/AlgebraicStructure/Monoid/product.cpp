#pragma once

/**
 * @docs product.md
 */
template <typename T>
struct ProductMonoid{
  using value_type = T;
  static value_type id(){return 1;}
  static value_type op(value_type a, value_type b){return a * b;}
};
