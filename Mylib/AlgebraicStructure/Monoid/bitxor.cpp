#pragma once

/**
 * @title Bitxor monoid
 * @docs bitxor.md
 */
namespace haar_lib {
  template <typename T>
  struct bitxor_monoid {
    using value_type = T;
    value_type operator()() const {return 0;}
    value_type operator()(value_type a, value_type b) const {return a ^ b;}
  };
}
