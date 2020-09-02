#pragma once
#include <utility>
#include <limits>
#include <algorithm>

/**
 * @docs with_max_index.md
 */
template <typename Monoid>
struct WithMaxIndex {
  using value_type = std::pair<typename Monoid::value_type, int64_t>;
  const static Monoid M;

  value_type operator()() const {
    return {M(), 0};
  }

  value_type operator()(const value_type &a, const value_type &b) const {
    if(a.first == b.first) return {a.first, std::max(a.second, b.second)};
    if(M(a.first, b.first) == a.first) return a;
    else return b;
  }
};
