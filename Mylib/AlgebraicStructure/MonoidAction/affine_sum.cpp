#pragma once
#include <utility>

/**
 * @title Range affine / Range sum
 * @docs affine_sum.md
 */
template <typename T, typename U>
struct AffineSum{
  using value_type_get = T;
  using value_type_update = std::pair<U, U>;

  static value_type_get id_get(){return 0;}
  static value_type_update id_update(){return {1, 0};}

  static value_type_get op_get(value_type_get a, value_type_get b){return a + b;}
  static value_type_update op_update(value_type_update a, value_type_update b){return {a.first * b.first, a.first * b.second + a.second};}

  static value_type_get op(value_type_get a, value_type_update b, int len){
    return b.first * a + b.second * len;
  }
};
