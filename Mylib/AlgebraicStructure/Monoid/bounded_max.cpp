#pragma once
#include <limits>
#include <algorithm>

/**
 * @title Bounded max monoid
 * @docs bounded_max.md
 */
namespace haar_lib {
  template <typename T>
  struct bounded_max_monoid {
    using value_type = T;

    value_type operator()() const {return std::numeric_limits<T>::lowest();}
    value_type operator()(const value_type &a, const value_type &b) const {
      return std::max(a, b);
    }
  };
}
