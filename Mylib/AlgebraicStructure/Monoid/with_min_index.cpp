#pragma once
#include <utility>
#include <limits>
#include <algorithm>

namespace haar_lib {
  namespace with_min_index_impl {
    template <typename T>
    struct value_index {
      T value;
      int index;
      value_index(){}
      value_index(T value, int index): value(value), index(index){}
    };
  }

  template <typename Monoid>
  struct with_min_index {
    using value_type = with_min_index_impl::value_index<typename Monoid::value_type>;
    const static Monoid M;

    value_type operator()() const {
      return {M(), std::numeric_limits<int>::max()};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if(a.value == b.value) return {a.value, std::min(a.index, b.index)};
      if(M(a.value, b.value) == a.value) return a;
      else return b;
    }
  };
}
