#pragma once

struct OrderingMonoid{
  using value_type = int;
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a ? a : b;}
};
