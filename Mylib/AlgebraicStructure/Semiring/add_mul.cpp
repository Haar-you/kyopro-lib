#pragma once

namespace haar_lib {
  template <typename T>
  struct add_mul_semiring {
    using value_type = T;
    value_type id_add() const {return 0;}
    value_type id_mul() const {return 1;}
    value_type add(value_type a, value_type b) const {return a + b;}
    value_type mul(value_type a, value_type b) const {return a * b;}
  };
}
