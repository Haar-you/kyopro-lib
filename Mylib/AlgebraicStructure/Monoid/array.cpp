#pragma once
#include <array>

/**
 * @title Array monoid
 * @docs array.md
 */
namespace haar_lib {
  template <typename Monoid, int B>
  struct array_monoid {
    using value_type = std::array<typename Monoid::value_type, B>;
    const static Monoid M;

    value_type operator()() const {
      value_type ret;
      ret.fill(M());
      return ret;
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      value_type ret;
      for(int i = 0; i < B; ++i) ret[i] = M(a[i], b[i]);
      return ret;
    }
  };
}
