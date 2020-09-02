#pragma once

/**
 * @tile Xor-and semiring
 * @docs xor_and.md
 */
template <typename T>
struct XorAndSemiring {
  using value_type = T;
  value_type id_add() const {return 0;}
  value_type id_mul() const {return ~(T)0;}
  value_type add(value_type a, value_type b) const {return a ^ b;}
  value_type mul(value_type a, value_type b) const {return a & b;}
};

