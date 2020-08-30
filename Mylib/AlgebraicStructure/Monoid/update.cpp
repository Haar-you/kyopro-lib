#pragma once
#include <optional>

/**
 * @docs update.md
 */
template <typename T>
struct UpdateMonoid{
  using value_type = std::optional<T>;
  value_type operator()() const {return std::nullopt;}
  value_type operator()(const value_type &a, const value_type &b) const {return (a ? a : b);}
};
