#pragma once
#include <array>

/**
 * @docs array.md
 */
template <typename Monoid, int B>
struct ArrayMonoid{
  using value_type = std::array<typename Monoid::value_type, B>;
  Monoid M;

  value_type id() const {
    value_type ret;
    ret.fill(M.id());
    return ret;
  }

  value_type op(const value_type &a, const value_type &b) const {
    value_type ret;
    for(int i = 0; i < B; ++i) ret[i] = M.op(a[i], b[i]);
    return ret;
  }
};
