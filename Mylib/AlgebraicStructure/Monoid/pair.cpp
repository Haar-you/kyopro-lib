#pragma once
#include <utility>

/**
 * @docs pair.md
 */
template <typename Monoid1, typename Monoid2>
struct PairMonoid{
  using value_type = std::pair<typename Monoid1::value_type, typename Monoid2::value_type>;
  Monoid1 M1;
  Monoid2 M2;

  value_type id() const {
    return {M1.id(), M2id()};
  }

  value_type op(const value_type &a, const value_type &b) const {
    return {M1.op(a.first, b.first), M2.op(a.second, b.second)};
  }
};
