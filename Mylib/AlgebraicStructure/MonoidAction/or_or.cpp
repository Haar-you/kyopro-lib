#pragma once

/**
 * @title Range bitor / Range bitor
 * @docs or_or.md
 */
template <typename T, typename U>
struct OrOr {
  using value_type_get = T;
  using value_type_update = U;

  value_type_get id_get() const {return 0;}
  value_type_update id_update() const {return 0;}

  value_type_get op_get(value_type_get a, value_type_get b) const {return a | b;}
  value_type_update op_update(value_type_update a, value_type_update b) const {return a | b;}

  value_type_get op(value_type_get a, value_type_update b, int len) const {
    return a | b;
  }
};
