#pragma once
#include <optional>

/**
 * @docs maybe_monoid.md
 */
template <typename Semigroup>
struct MaybeMonoid{
  using value_type = std::optional<typename Semigroup::value_type>;
  
  static value_type id(){return {};}
  static value_type op(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;
    return {Semigroup::op(*a, *b)};
  }
};
