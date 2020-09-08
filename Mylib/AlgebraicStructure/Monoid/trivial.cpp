#pragma once

/**
 * @title Trivial monoid
 * @docs trivial.md
 */
namespace haar_lib {
  template <typename T>
  struct TrivialMonoid {
    using value_type = T;
    value_type operator()() const {return T();}
    value_type operator()(const value_type &, const value_type &) const {return T();}
  };
}
