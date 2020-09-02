#pragma once

/**
 * @title Product monoid
 * @docs product.md
 */
template <typename T>
struct ProductMonoid {
  using value_type = T;
  value_type operator()() const {return 1;}
  value_type operator()(value_type a, value_type b) const {return a * b;}
};
