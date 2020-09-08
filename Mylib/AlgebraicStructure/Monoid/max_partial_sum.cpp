#pragma once
#include <optional>
#include <algorithm>
#include <iostream>

/**
 * @title Max partial sum monoid
 * @docs max_partial_sum.md
 */
namespace haar_lib {
  template <typename T>
  struct MaxPartialSumMonoid {
    struct MaxPartialSum {
      T sum, left_max, right_max, partial_max;
      MaxPartialSum(T x): sum(x), left_max(x), right_max(x), partial_max(x){}
      MaxPartialSum(T sum, T left_max, T right_max, T partial_max): sum(sum), left_max(left_max), right_max(right_max), partial_max(partial_max){}

      friend std::ostream& operator<<(std::ostream &s, const MaxPartialSum &a){
        s << "(" << "sum: " << a.sum << ", "
          << "left_max: " << a.left_max << ", "
          << "right_max: " << a.right_max << ", "
          << "partial_max: " << a.partial_max << ")";
        return s;
      }
    };

    using value_type = std::optional<MaxPartialSum>;

    value_type operator()() const {
      return std::nullopt;
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if(not a) return b;
      if(not b) return a;

      return MaxPartialSum(
        a->sum + b->sum,
        std::max(a->left_max, a->sum + std::max(b->left_max, b->sum)),
        std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),
        std::max({a->partial_max, b->partial_max, a->right_max + b->left_max})
      );
    }
  };
}
