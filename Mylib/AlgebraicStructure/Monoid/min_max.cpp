#pragma once
#include <optional>
#include <algorithm>

namespace haar_lib {
  namespace min_max_monoid_impl {
    template <typename T>
    struct internal_value {
      std::optional<T> min, max;
      internal_value(): min(std::nullopt), max(std::nullopt){}
      internal_value(T value): min(value), max(value){}
    };
  }

  template <typename T>
  struct min_max_monoid {
    using value_type = min_max_monoid_impl::internal_value<T>;

    value_type operator()() const {
      return {};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      value_type ret;
      if(not a.min) ret.min = b.min;
      if(not b.min) ret.min = a.min;
      if(a.min and b.min) ret.min = std::min(a.min.value(), b.min.value());

      if(not a.max) ret.max = b.max;
      if(not b.max) ret.max = a.max;
      if(a.max and b.max) ret.max = std::max(a.max.value(), b.max.value());

      return ret;
    }
  };
}
