#pragma once
#include <array>

/**
 * @title Range xor / Range sum
 * @docs xor_sum.md
 */
namespace haar_lib {
  template <typename U, int B>
  struct bitxor_sum {
    using value_type_get = typename std::array<int, B>;
    using value_type_update = U;

    value_type_get id_get() const {
      value_type_get ret;
      ret.fill(0);
      return ret;
    }
    value_type_update id_update() const {return 0;}

    value_type_get op_get(const value_type_get &a, const value_type_get &b){
      value_type_get ret;
      for(int i = 0; i < B; ++i) ret[i] = a[i] + b[i];
      return ret;
    }
    value_type_update op_update(value_type_update a, value_type_update b) const {return a ^ b;}

    value_type_get op(const value_type_get &a, const value_type_update &b, int len) const {
      auto ret = a;
      for(int i = 0; i < B; ++i) if((b >> i) & 1) ret[i] = len - ret[i];
      return ret;
    }
  };
}
