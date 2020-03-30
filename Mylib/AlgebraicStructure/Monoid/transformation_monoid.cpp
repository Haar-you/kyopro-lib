#pragma once
#include <array>

/**
 * @see https://codeforces.com/contest/911/submission/63237734 (TLE)
 */
template <size_t N>
struct TransformationMonoid{
  using value_type = std::array<int,N>;

  inline static value_type id(){
    value_type ret;
    for(int i = 0; i < (int)N; ++i) ret[i] = i;
    return ret;
  }

  inline static value_type op(const value_type &a, const value_type &b){
    value_type ret;
    for(int i = 0; i < (int)N; ++i) ret[i] = a[b[i]];
    return ret;
  }
};
