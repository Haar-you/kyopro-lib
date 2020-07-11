#pragma once
#include <optional>

/**
 * @title Range update / Range bitor
 * @docs update_or.md
 */
template <typename T, typename U>
struct UpdateOr{
  using value_type_get = T;
  using value_type_update = std::optional<U>;

  static value_type_get id_get(){return 0;}
  static value_type_update id_update(){return {};}

  static value_type_get op_get(value_type_get a, value_type_get b){return a | b;}
  static value_type_update op_update(value_type_update a, value_type_update b){return (a ? a : b );}

  static value_type_get op(value_type_get a, value_type_update b, int len){
    return b ? *b : a;
  }
};
