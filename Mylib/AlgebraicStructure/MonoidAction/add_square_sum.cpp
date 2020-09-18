#pragma once
#include <utility>

namespace haar_lib {
  template <typename MonoidGet, typename MonoidUpdate>
  struct add_square_sum {
    using value_type_get = typename MonoidGet::value_type;
    using value_type_update = typename MonoidUpdate::value_type;

    value_type_get operator()(const value_type_get &a, const value_type_update &b, int len) const {
      return {std::get<0>(a) + b * len, std::get<1>(a) + b * (2 * std::get<0>(a) + b * len)};
    }
  };
}
