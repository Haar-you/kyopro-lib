#pragma once
#include <cmath>
#include <vector>

namespace haar_lib {
  std::vector<double> quadratic_equation(double a, double b, double c){
    double d = b * b - 4 * a * c;
    if(d < 0) return {};

    double x1 = (-b - std::sqrt(d)) / (2 * a);
    double x2 = (-b + std::sqrt(d)) / (2 * a);
    return {x1, x2};
  }
}
