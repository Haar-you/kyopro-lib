#pragma once
#include <utility>

/**
 * @docs with_count.md
 */
template <typename Monoid>
struct WithCount{
  using value_type = std::pair<typename Monoid::value_type, int64_t>;
  Monoid M;

  value_type id() const {
    return {M.id(), 1};
  }

  value_type op(const value_type &a, const value_type &b) const {
    if(a.first == b.first) return {a.first, a.second + b.second};
    if(M.op(a.first, b.first) == a.first) return a;
    else return b;
  }
};
