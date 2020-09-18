#pragma once
#include <utility>
#include <cstdint>

namespace haar_lib {
  namespace with_count_impl {
    template <typename T>
    struct inner_value {
      T value;
      int64_t count;
      inner_value(): value(T()), count(0){}
      inner_value(T value): value(value), count(1){}
      inner_value(T value, int64_t count): value(value), count(count){}
    };
  }

  template <typename Monoid>
  struct with_count {
    using value_type = with_count_impl::inner_value<typename Monoid::value_type>;
    const static Monoid M;

    value_type operator()() const {
      return {M(), 0};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if(a.value == b.value) return {a.value, a.count + b.count};
      if(M(a.value, b.value) == a.value) return a;
      return b;
    }
  };
}
