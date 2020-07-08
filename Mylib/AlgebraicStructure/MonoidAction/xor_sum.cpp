#pragma once
#include "Mylib/AlgebraicStructure/Monoid/array.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/Monoid/bitxor.cpp"

/**
 * @docs xor_sum.md
 */
template <typename U, int B>
struct XorSum{
  using monoid_get = ArrayMonoid<SumMonoid<int>, B>;
  using monoid_update = BitXorMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  static value_type_get id_get(){return monoid_get::id();}
  static value_type_update id_update(){return monoid_update::id();}

  static value_type_get op_get(const value_type_get &a, const value_type_get &b){return monoid_get::op(a, b);}
  static value_type_update op_update(value_type_update a, value_type_update b){return monoid_update::op(a, b);}

  static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    auto ret = a;
    for(int i = 0; i < B; ++i) if((b >> i) & 1) ret[i] = len - ret[i];
    return ret;
  }
};
