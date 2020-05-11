#pragma once
#include <utility>
#include <limits>
#include <algorithm>

/**
 * @docs with_min_index.md
 */
template <typename Monoid>
struct WithMinIndex{
  using value_type = std::pair<typename Monoid::value_type, int64_t>;

  constexpr inline static value_type id(){
    return {Monoid::id(), std::numeric_limits<int64_t>::max()};
  }

  constexpr inline static value_type op(const value_type &a, const value_type &b){
    if(a.first == b.first) return {a.first, std::min(a.second, b.second)};
    if(Monoid::op(a.first, b.first) == a.first) return a;
    else return b;
  }
};
