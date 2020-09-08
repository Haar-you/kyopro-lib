#pragma once
#include <utility>

/**
 * @title Range affine / Range sum
 * @docs affine_sum.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct AffineSum {
    using value_type_get = T;
    using value_type_update = std::pair<U, U>;

    value_type_get id_get() const {return 0;}
    value_type_update id_update() const {return {1, 0};}

    value_type_get op_get(value_type_get a, value_type_get b) const {return a + b;}
    value_type_update op_update(value_type_update a, value_type_update b) const {return {a.first * b.first, a.first * b.second + a.second};}

    value_type_get op(value_type_get a, value_type_update b, int len) const {
      return b.first * a + b.second * len;
    }
  };
}
