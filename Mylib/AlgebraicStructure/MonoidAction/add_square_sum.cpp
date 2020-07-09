#pragma once
#include <utility>

/**
 * @title Range add / Range square sum
 * @docs add_square_sum.cpp
 */
template <typename T>
struct AddSquareSum{
  using value_type_get = std::pair<T, T>;
  using value_type_update = T;

  static value_type_get id_get(){
    return std::make_pair(0, 0);
  }

  static value_type_update id_update(){
    return 0;
  }

  static value_type_get op_get(const value_type_get &a, const value_type_get &b){
    return std::make_pair(a.first + b.first, a.second + b.second);
  }

  static value_type_update op_update(const value_type_update &a, const value_type_update &b){
    return a + b;
  }
  
  static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    return std::make_pair(a.first + b * len, a.second + b * (2 * a.first + b * len));
  }
};
