#pragma once
#include <optional>

/**
 * @title Update monoid
 * @docs update.md
 */
namespace haar_lib {
  template <typename T>
  struct update_monoid {
    using value_type = std::optional<T>;
    value_type operator()() const {return std::nullopt;}
    value_type operator()(const value_type &a, const value_type &b) const {return (a ? a : b);}
  };
}
