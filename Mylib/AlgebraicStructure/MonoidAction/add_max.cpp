#pragma once
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/Monoid/max.cpp"

/**
 * @docs add_max.md
 */
template <typename T, typename U>
struct AddMax{
  using monoid_get = MaxMonoid<T>;
  using monoid_update = SumMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  static value_type_get id_get(){return monoid_get::id();}
  static value_type_update id_update(){return monoid_update::id();}

  static value_type_get op_get(value_type_get a, value_type_get b){return monoid_get::op(a, b);}
  static value_type_update op_update(value_type_update a, value_type_update b){return monoid_update::op(a, b);}
  
  static value_type_get op(value_type_get a, value_type_update b, int len){
    if(a) return {*a + b};
    return {};
  }
};
