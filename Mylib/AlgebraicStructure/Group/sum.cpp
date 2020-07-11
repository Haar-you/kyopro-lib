#pragma once

/**
 * @docs sum.md
 */
template <typename T>
struct SumGroup{
  using value_type = T;

  value_type id() const {return 0;}
  value_type op(const value_type &a, const value_type &b) const {return a + b;}
  value_type inv(const value_type &a) const {return -a;}
};
