#pragma once

/**
 * @title Ordering monoid
 * @docs ordering.md
 */
namespace haar_lib {
  struct OrderingMonoid {
    using value_type = int;
    value_type operator()() const {return 0;}
    value_type operator()(const value_type &a, const value_type &b) const {return a ? a : b;}
  };
}
