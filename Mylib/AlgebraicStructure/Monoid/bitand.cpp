#pragma once

/**
 * @title Bitand monoid
 * @docs bitand.md
 */
namespace haar_lib {
  template <typename T>
  struct bitand_monoid {
    using value_type = T;
    value_type operator()() const {return ~(value_type)0;}
    value_type operator()(value_type a, value_type b) const {return a & b;}
  };
}
