#pragma once
#include <utility>

/**
 * @see https://atcoder.jp/contests/arc008/submissions/7996520
 * @see https://judge.yosupo.jp/submission/2048
 */

template <typename T>
struct AffineMonoid{
  using value_type = std::pair<T, T>;
  constexpr inline static value_type id(){return std::make_pair(1, 0);}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::make_pair(a.first * b.first, a.first * b.second + a.second);}
};
