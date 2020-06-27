#pragma once

/**
 * @docs xor_and.md
 */
template <typename T>
struct XorAndSemiring{
  using value_type = T;
  static value_type id_add(){return 0;}
  static value_type id_mul(){return ~(T)0;}
  static value_type add(value_type a, value_type b){return a ^ b;}
  static value_type mul(value_type a, value_type b){return a & b;}
};

