#pragma once

namespace haar_lib {
  template <typename MonoidGet, typename MonoidUpdate>
  struct add_min {
    using value_type_get = typename MonoidGet::value_type;
    using value_type_update = typename MonoidUpdate::value_type;

    value_type_get operator()(value_type_get a, value_type_update b, int) const {
      if(a) return {*a + b};
      return {};
    }
  };
}
