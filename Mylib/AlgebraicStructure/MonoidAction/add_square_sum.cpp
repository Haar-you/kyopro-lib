#pragma once
#include <utility>

namespace haar_lib {
  template <typename MonoidUpdate>
  struct add_square_sum {
    struct internal_type {
      using value_type = typename MonoidUpdate::value_type;
      value_type sum, square_sum;
      internal_type(value_type value) : sum(value), square_sum(value * value) {}
      internal_type(value_type sum, value_type square_sum) : sum(sum), square_sum(square_sum) {}
    };

    struct monoid_get {
      using value_type = internal_type;
      value_type operator()() const { return {0, 0}; };
      value_type operator()(const value_type &a, const value_type &b) { return {a.sum + b.sum, a.square_sum + b.square_sum}; }
    };

    using monoid_update     = MonoidUpdate;
    using value_type_get    = typename monoid_get::value_type;
    using value_type_update = typename MonoidUpdate::value_type;

    value_type_get operator()(const value_type_get &a, const value_type_update &b, int len) const {
      return {
          a.sum + b * len,
          a.square_sum + b * (2 * a.sum + b * len)};
    }
  };
}  // namespace haar_lib
