#pragma once

/**
 * @title Dual monoid
 * @docs dual.md
 */
namespace haar_lib {
  template <typename Monoid>
  struct dual_monoid {
    using value_type = typename Monoid::value_type;
    const static Monoid M;
    value_type operator()() const {return M();}
    value_type operator()(const value_type &a, const value_type &b) const {return M(b, a);}
  };
}
