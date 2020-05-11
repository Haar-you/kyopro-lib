#pragma once
#include <utility>

/**
 * @docs pair.md
 */
template <typename M1, typename M2>
struct PairMonoid{
  using value_type = std::pair<typename M1::value_type, typename M2::value_type>;

  constexpr inline static value_type id(){
    return {M1::id(), M2::id()};
  }

  constexpr inline static value_type op(const value_type &a, const value_type &b){
    return {M1::op(a.first, b.first), M2::op(a.second, b.second)};
  }
};
