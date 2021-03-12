#pragma once
#include <tuple>
#include <algorithm>

namespace haar_lib {
  namespace max_contiguous_monoid_impl {
    struct internal_value {
      int count, left, right, length;
      internal_value(){}
      internal_value(int count, int left, int right, int length):
        count(count), left(left), right(right), length(length){}
      internal_value(int x): count(x ? 1 : 0), left(x ? 1 : 0), right(x ? 1 : 0), length(1){}
    };
  }

  struct max_contiguous_monoid {
    using value_type = max_contiguous_monoid_impl::internal_value;

    value_type operator()() const {
      return {0, 0, 0, 0};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      return {
              std::max({a.count, b.count, a.right + b.left}),
              a.count == a.length ? a.count + b.left : a.left,
              b.count == b.length ? b.count + a.right : b.right,
              a.length + b.length
      };
    }
  };
}
