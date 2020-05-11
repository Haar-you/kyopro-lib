#pragma once
#include <array>

/**
 * @docs array.md
 */
template <typename Monoid, int B>
struct ArrayMonoid{
  using value_type = std::array<typename Monoid::value_type, B>;

  inline static value_type id(){
    value_type ret;
    ret.fill(Monoid::id());
    return ret;
  }

  inline static value_type op(const value_type &a, const value_type &b){
    value_type ret;
    for(int i = 0; i < B; ++i) ret[i] = Monoid::op(a[i], b[i]);
    return ret;
  }
};
