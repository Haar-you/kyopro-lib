#pragma once

template <typename T>
struct XorAndSemiring{
  using value_type = T;
  constexpr static value_type ZERO = 0;
  constexpr static value_type ONE = ~ZERO;
  constexpr inline static value_type id_add(){return ZERO;}
  constexpr inline static value_type id_mul(){return ONE;}
  constexpr inline static value_type add(const value_type &a, const value_type &b){return a ^ b;}
  constexpr inline static value_type mul(const value_type &a, const value_type &b){return a & b;}
};

