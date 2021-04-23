#pragma once
#include <algorithm>
#include <limits>
#include <utility>

namespace haar_lib {
  namespace with_max_index_impl {
    template <typename T>
    struct value_index {
      T value;
      int index;
      value_index() {}
      value_index(T value, int index) : value(value), index(index) {}
    };
  }  // namespace with_max_index_impl

  template <typename Monoid>
  struct with_max_index {
    using value_type = with_max_index_impl::value_index<typename Monoid::value_type>;
    const static Monoid M;

    value_type operator()() const {
      return {M(), 0};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if (a.value == b.value) return {a.value, std::max(a.index, b.index)};
      if (M(a.value, b.value) == a.value)
        return a;
      else
        return b;
    }
  };
}  // namespace haar_lib
