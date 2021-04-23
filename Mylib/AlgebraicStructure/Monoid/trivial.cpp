#pragma once

namespace haar_lib {
  template <typename T>
  struct trivial_monoid {
    using value_type = T;
    value_type operator()() const { return T(); }
    value_type operator()(const value_type &, const value_type &) const { return T(); }
  };
}  // namespace haar_lib
