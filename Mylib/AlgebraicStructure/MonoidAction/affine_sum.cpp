#pragma once

namespace haar_lib {
  template <typename MonoidUpdate, typename MonoidGet>
  struct affine_sum {
    using monoid_get        = MonoidGet;
    using monoid_update     = MonoidUpdate;
    using value_type_get    = typename MonoidGet::value_type;
    using value_type_update = typename MonoidUpdate::value_type;

    value_type_get operator()(value_type_get a, value_type_update b, int len) const {
      return b.first * a + b.second * len;
    }
  };
}  // namespace haar_lib
