#pragma once
#include <algorithm>
#include <optional>

/**
 * @docs max.md
 */
template <typename T>
struct MaxMonoid{
  using value_type = std::optional<T>;
  
  static value_type id(){return {};}
  static value_type op(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;
    return {std::max(*a, *b)};
  }
};
