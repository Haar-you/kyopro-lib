#pragma once

/**
 * @docs add_mul.md
 */
template <typename T>
struct AddMulSemiring{
  using value_type = T;
  constexpr inline static value_type id_add(){return 0;}
  constexpr inline static value_type id_mul(){return 1;}
  constexpr inline static value_type add(const value_type &a, const value_type &b){return a + b;}
  constexpr inline static value_type mul(const value_type &a, const value_type &b){return a * b;}
};
