#pragma once
#include <optional>
#include <algorithm>

/**
 * @docs min_add.md
 */
template <typename T>
struct MinAddSemiring{
  using value_type = std::optional<T>;

  static value_type id_add(){return std::nullopt;}
  static value_type id_mul(){return 0;}

  static value_type add(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;
    return {std::min(*a, *b)};
  }
  static value_type mul(const value_type &a, const value_type &b){
    if(not a or not b) return {};
    return {*a + *b};
  }
};
