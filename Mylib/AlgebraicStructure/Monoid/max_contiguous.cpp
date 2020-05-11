#pragma once
#include <tuple>

/**
 * @docs max_contiguous.md
 */
struct MaxContiguousMonoid{
  using value_type = std::tuple<int, int, int, int>;

  static value_type id(){
    return {0, 0, 0, 0};
  }

  static value_type op(const value_type &a, const value_type &b){
    auto [ca, la, ra, lena] = a;
    auto [cb, lb, rb, lenb] = b;

    return {
            std::max({ca, cb, ra + lb}),
            ca == lena ? ca + lb : la,
            cb == lenb ? cb + ra : rb,
            lena + lenb
    };
  }

  static value_type zero(){
    return {0, 0, 0, 1};
  }
  
  static value_type one(){
    return {1, 1, 1, 1};
  }
};
