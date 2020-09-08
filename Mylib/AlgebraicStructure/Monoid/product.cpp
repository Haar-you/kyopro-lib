#pragma once

/**
 * @title Product monoid
 * @docs product.md
 */
namespace haar_lib {
  template <typename T>
  struct product_monoid {
    using value_type = T;
    value_type operator()() const {return 1;}
    value_type operator()(value_type a, value_type b) const {return a * b;}
  };
}
