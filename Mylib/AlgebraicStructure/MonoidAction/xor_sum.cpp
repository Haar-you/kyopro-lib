#pragma once
#include "Mylib/AlgebraicStructure/Monoid/parallel_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/xor_monoid.cpp"

/**
 * @docs xor_sum.md
 */
template <typename U, int B>
struct XorSum{
  using monoid_get = ParallelMonoid<SumMonoid<int>, B>;
  using monoid_update = XorMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    auto ret = a;
    for(int i = 0; i < B; ++i) if((b >> i) & 1) ret[i] = len - ret[i];
    return ret;
  }
};