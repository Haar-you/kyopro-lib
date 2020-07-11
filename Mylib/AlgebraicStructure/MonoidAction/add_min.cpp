#pragma once
#include <optional>

/**
 * @title Range add / Range min
 * @docs add_min.md
 */
template <typename T, typename U>
struct AddMin{
  using value_type_get = std::optional<T>;
  using value_type_update = U;

  static value_type_get id_get(){return {};}
  static value_type_update id_update(){return 0;}

  static value_type_get op_get(value_type_get a, value_type_get b){
    if(not a) return b;
    if(not b) return a;
    return {std::min(*a, *b)};
  }
  static value_type_update op_update(value_type_update a, value_type_update b){return a + b;}

  static value_type_get op(value_type_get a, value_type_update b, int){
    if(a) return {*a + b};
    return {};
  }
};
