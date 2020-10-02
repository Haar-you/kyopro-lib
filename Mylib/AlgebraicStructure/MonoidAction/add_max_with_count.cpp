#pragma once

namespace haar_lib {
  template <typename MonoidUpdate, typename MonoidGet>
  struct add_max_with_count {
    using monoid_get = MonoidGet;
    using monoid_update = MonoidUpdate;
    using value_type_get = typename MonoidGet::value_type;
    using value_type_update = typename MonoidUpdate::value_type;

    value_type_get operator()(const value_type_get &a, const value_type_update &b, int) const {
      return {a.value ? a.value.value() + b : a.value, a.count};
    }
  };
}
