#pragma once
#include <optional>

/**
 * @title Range add / Range min
 * @docs add_min.md
 */
template <typename T, typename U>
struct AddMin {
  using value_type_get = std::optional<T>;
  using value_type_update = U;

  value_type_get id_get() const {return {};}
  value_type_update id_update() const {return 0;}

  value_type_get op_get(value_type_get a, value_type_get b) const {
    if(not a) return b;
    if(not b) return a;
    return {std::min(*a, *b)};
  }
  value_type_update op_update(value_type_update a, value_type_update b) const {return a + b;}

  value_type_get op(value_type_get a, value_type_update b, int) const {
    if(a) return {*a + b};
    return {};
  }
};
