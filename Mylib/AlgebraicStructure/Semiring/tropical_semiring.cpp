#pragma once
#include <optional>
#include <algorithm>

template <typename T>
struct TropicalSemiring{
  using value_type = std::optional<T>;

  constexpr inline static value_type id_add(){return std::nullopt;}
  constexpr inline static value_type id_mul(){return 0;}

  constexpr inline static value_type add(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;
    return {std::min(*a, *b)};
  }
  constexpr inline static value_type mul(const value_type &a, const value_type &b){
    if(not a or not b) return {};
    return {*a + *b};
  }
};
