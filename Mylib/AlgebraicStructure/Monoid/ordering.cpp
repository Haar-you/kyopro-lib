#pragma once

namespace haar_lib {
  struct ordering_monoid {
    using value_type = int;
    value_type operator()() const { return 0; }
    value_type operator()(const value_type &a, const value_type &b) const { return a ? a : b; }
  };
}  // namespace haar_lib
