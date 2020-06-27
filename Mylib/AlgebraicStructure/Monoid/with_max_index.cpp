#pragma once
#include <utility>
#include <limits>
#include <algorithm>

/**
 * @docs with_max_index.md
 */
template <typename Monoid>
struct WithMaxIndex{
  using value_type = std::pair<typename Monoid::value_type, int64_t>;

  static value_type id(){
    return {Monoid::id(), 0};
  }

  static value_type op(const value_type &a, const value_type &b){
    if(a.first == b.first) return {a.first, std::max(a.second, b.second)};
    if(Monoid::op(a.first, b.first) == a.first) return a;
    else return b;
  }
};
