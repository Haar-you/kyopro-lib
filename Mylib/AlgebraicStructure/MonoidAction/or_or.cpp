#pragma once

/**
 * @title Range bitor / Range bitor
 * @docs or_or.md
 */
template <typename T, typename U>
struct OrOr{
  using value_type_get = T;
  using value_type_update = U;

  static value_type_get id_get(){return 0;}
  static value_type_update id_update(){return 0;}

  static value_type_get op_get(value_type_get a, value_type_get b){return a | b;}
  static value_type_update op_update(value_type_update a, value_type_update b){return a | b;}

  static value_type_get op(value_type_get a, value_type_update b, int len){
    return a | b;
  }
};
