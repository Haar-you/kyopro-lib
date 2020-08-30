#pragma once

/**
 * @docs sum.md
 */
template <typename T>
struct SumMonoid{
  using value_type = T;
  value_type operator()() const {return 0;}
  value_type operator()(value_type a, value_type b) const {return a + b;}
};
