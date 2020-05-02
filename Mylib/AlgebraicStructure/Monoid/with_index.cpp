#pragma once
#include <utility>

/**
 * @docs with_index.md
 */
template <typename Monoid, typename Index>
struct WithIndex{
  using value_type = std::pair<typename Monoid::value_type, typename Index::value_type>;

  constexpr inline static value_type id(){
    return {Monoid::id(), Index::id()};
  }

  constexpr inline static value_type op(const value_type &a, const value_type &b){
    if(a.first == b.first) return {a.first, Index::op(a.second, b.second)};
    if(Monoid::op(a.first, b.first) == a.first) return a;
    else return b;
  }
};
