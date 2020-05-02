#pragma once
#include <cmath>
#include <vector>

/**
 * @title 二次方程式の実数解
 * @docs quadratic_equation.md
 */
std::vector<double> quadratic_equation(double a, double b, double c){
  double d = b*b - 4*a*c;
  if(d < 0) return {};
  
  double x1 = (-b - std::sqrt(d)) / (2 * a);
  double x2 = (-b + std::sqrt(d)) / (2 * a);
  return {x1, x2};
}
