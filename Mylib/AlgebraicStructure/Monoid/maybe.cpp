#pragma once
#include <optional>

/**
 * @docs maybe.md
 */
template <typename Semigroup>
struct MaybeMonoid{
  using value_type = std::optional<typename Semigroup::value_type>;
  const static Semigroup S;
  
  value_type operator()() const {return std::nullopt;}
  value_type operator()(const value_type &a, const value_type &b) const {
    if(not a) return b;
    if(not b) return a;
    return {S(*a, *b)};
  }
};
