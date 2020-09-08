#pragma once
#include <utility>

/**
 * @title Affine monoid
 * @docs affine.md
 */
namespace haar_lib {
  template <typename T>
  struct affine_monoid {
    using value_type = std::pair<T, T>;
    value_type operator()() const {return std::make_pair(1, 0);}
    value_type operator()(const value_type &a, const value_type &b) const {
      return std::make_pair(a.first * b.first, a.first * b.second + a.second);
    }
  };
}
