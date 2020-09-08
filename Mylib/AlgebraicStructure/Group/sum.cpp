#pragma once

/**
 * @title Sum group
 * @docs sum.md
 */
namespace haar_lib {
  template <typename T>
  struct sum_group {
    using value_type = T;

    value_type operator()() const {return 0;}
    value_type operator()(const value_type &a, const value_type &b) const {return a + b;}
    value_type inv(const value_type &a) const {return -a;}
  };
}
