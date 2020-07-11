#pragma once

/**
 * @docs ordering.md
 */
struct OrderingMonoid{
  using value_type = int;
  value_type id() const {return 0;}
  value_type op(const value_type &a, const value_type &b) const {return a ? a : b;}
};
