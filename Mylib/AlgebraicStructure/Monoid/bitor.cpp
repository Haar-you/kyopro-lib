#pragma once

/**
 * @title Bitor monoid
 * @docs bitor.md
 */
namespace haar_lib {
  template <typename T>
  struct BitOrMonoid {
    using value_type = T;
    value_type operator()() const {return 0;}
    value_type operator()(value_type a, value_type b) const {return a | b;}
  };
}
