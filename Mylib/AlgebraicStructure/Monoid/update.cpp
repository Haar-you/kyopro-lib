#pragma once
#include <optional>

/**
 * @docs update.md
 */
template <typename T>
struct UpdateMonoid{
  using value_type = std::optional<T>;
  static value_type id(){return std::nullopt;}
  static value_type op(const value_type &a, const value_type &b){return (a ? a : b);}
};
