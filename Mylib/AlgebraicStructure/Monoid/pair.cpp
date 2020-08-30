#pragma once
#include <utility>

/**
 * @docs pair.md
 */
template <typename Monoid1, typename Monoid2>
struct PairMonoid{
  using value_type = std::pair<typename Monoid1::value_type, typename Monoid2::value_type>;
  const static Monoid1 M1;
  const static Monoid2 M2;

  value_type operator()() const {
    return {M1(), M2()};
  }

  value_type operator()(const value_type &a, const value_type &b) const {
    return {M1(a.first, b.first), M2(a.second, b.second)};
  }
};
