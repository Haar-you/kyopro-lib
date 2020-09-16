#pragma once
#include <utility>
#include <limits>
#include <algorithm>

namespace haar_lib {
  template <typename Monoid>
  struct with_min_index {
    using value_type = std::pair<typename Monoid::value_type, int64_t>;
    const static Monoid M;

    value_type operator()() const {
      return {M(), std::numeric_limits<int64_t>::max()};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if(a.first == b.first) return {a.first, std::min(a.second, b.second)};
      if(M(a.first, b.first) == a.first) return a;
      else return b;
    }
  };
}
