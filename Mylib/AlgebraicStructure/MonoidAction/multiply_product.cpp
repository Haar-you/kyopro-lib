#pragma once
#include "Mylib/AlgebraicStructure/Monoid/monoid_utils.cpp"

namespace haar_lib {
  template <typename MonoidGet, typename MonoidUpdate>
  struct multiply_product {
    using value_type_get = typename MonoidGet::value_type;
    using value_type_update = typename MonoidUpdate::value_type;

    value_type_get operator()(value_type_get a, value_type_update b, int len) const {
      return a * times<MonoidUpdate>(b, len);
    }
  };
}
