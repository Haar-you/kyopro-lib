#pragma once
#include <optional>
#include <algorithm>

/**
 * @title Max partial sum monoid
 * @docs max_partial_sum.md
 */
template <typename T>
struct MaxPartialSumMonoid {
  struct MaxPartialSum {
    T sum, left_max, right_max, partial_max;
    static auto make(T x){return MaxPartialSum({x, x, x, x});}
  };

  using value_type = std::optional<MaxPartialSum>;

  value_type operator()() const {
    return std::nullopt;
  }

  value_type operator()(const value_type &a, const value_type &b) const {
    if(not a) return b;
    if(not b) return a;

    return {
            {
             a->sum + b->sum,
             std::max(a->left_max, a->sum + std::max(b->left_max, b->sum)),
             std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),
             std::max({a->partial_max, b->partial_max, a->right_max + b->left_max})
            }
    };
  }
};
