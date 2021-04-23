#pragma once
#include <algorithm>
#include <iostream>
#include <optional>

namespace haar_lib {
  namespace max_partial_sum_monoid_impl {
    template <typename T>
    struct max_partial_sum {
      T sum, left_max, right_max, partial_max;
      max_partial_sum() {}
      max_partial_sum(T x) : sum(x), left_max(x), right_max(x), partial_max(x) {}
      max_partial_sum(T sum, T left_max, T right_max, T partial_max) : sum(sum), left_max(left_max), right_max(right_max), partial_max(partial_max) {}

      friend std::ostream &operator<<(std::ostream &s, const max_partial_sum &a) {
        s << "("
          << "sum: " << a.sum << ", "
          << "left_max: " << a.left_max << ", "
          << "right_max: " << a.right_max << ", "
          << "partial_max: " << a.partial_max << ")";
        return s;
      }
    };
  }  // namespace max_partial_sum_monoid_impl

  template <typename T>
  struct max_partial_sum_monoid {
    using max_partial_sum = max_partial_sum_monoid_impl::max_partial_sum<T>;
    using value_type      = std::optional<max_partial_sum>;

    value_type operator()() const {
      return std::nullopt;
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if (not a) return b;
      if (not b) return a;

      return max_partial_sum(
          a->sum + b->sum,
          std::max(a->left_max, a->sum + std::max(b->left_max, b->sum)),
          std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),
          std::max({a->partial_max, b->partial_max, a->right_max + b->left_max}));
    }
  };
}  // namespace haar_lib
