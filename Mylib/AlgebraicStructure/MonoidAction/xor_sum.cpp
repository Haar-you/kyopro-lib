#pragma once
#include <array>

/**
 * @title Range xor / Range sum
 * @docs xor_sum.md
 */
template <typename U, int B>
struct XorSum{
  using value_type_get = typename std::array<int, B>;
  using value_type_update = typename U;

  value_type_get id_get() const {
    value_type ret;
    ret.fill(M.id());
    return ret;
  }
  value_type_update id_update() const {return 0;}

  value_type_get op_get(const value_type_get &a, const value_type_get &b){
    value_type ret;
    for(int i = 0; i < B; ++i) ret[i] = M.op(a[i], b[i]);
    return ret;
  }
  value_type_update op_update(value_type_update a, value_type_update b) const {return a ^ b;}

  value_type_get op(const value_type_get &a, const value_type_update &b, int len) const {
    auto ret = a;
    for(int i = 0; i < B; ++i) if((b >> i) & 1) ret[i] = len - ret[i];
    return ret;
  }
};
