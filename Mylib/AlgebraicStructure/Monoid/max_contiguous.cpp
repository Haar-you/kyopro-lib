#pragma once
#include <tuple>

/**
 * @title Max contiguous monoid
 * @docs max_contiguous.md
 */
struct MaxContiguousMonoid {
  using value_type = std::tuple<int, int, int, int>;

  value_type operator()() const {
    return {0, 0, 0, 0};
  }

  value_type operator()(const value_type &a, const value_type &b) const {
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
