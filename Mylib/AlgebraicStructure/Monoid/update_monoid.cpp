#pragma once
#include <optional>

/**
 * @docs update_monoid.md
 */
template <typename T>
struct UpdateMonoid{
  using value_type = std::optional<T>;
  constexpr inline static value_type id(){return std::nullopt;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return (a ? a : b);}
};
