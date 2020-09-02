#pragma once
#include <utility>

/**
 * @title Range add / Range square sum
 * @docs add_square_sum.cpp
 */
template <typename T>
struct AddSquareSum {
  using value_type_get = std::pair<T, T>;
  using value_type_update = T;

  value_type_get id_get() const {
    return std::make_pair(0, 0);
  }

  value_type_update id_update() const {
    return 0;
  }

  value_type_get op_get(const value_type_get &a, const value_type_get &b) const {
    return std::make_pair(a.first + b.first, a.second + b.second);
  }

  value_type_update op_update(const value_type_update &a, const value_type_update &b) const {
    return a + b;
  }

  value_type_get op(const value_type_get &a, const value_type_update &b, int len) const {
    return std::make_pair(a.first + b * len, a.second + b * (2 * a.first + b * len));
  }
};
