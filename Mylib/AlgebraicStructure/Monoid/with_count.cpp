#pragma once
#include <utility>

template <typename Monoid>
struct WithCount{
  using value_type = std::pair<typename Monoid::value_type, int64_t>;

  constexpr inline static value_type id(){
    return {Monoid::id(), 1};
  }

  constexpr inline static value_type op(const value_type &a, const value_type &b){
    if(a.first == b.first) return {a.first, a.second + b.second};
    if(Monoid::op(a.first, b.first) == a.first) return a;
    else return b;
  }
};
