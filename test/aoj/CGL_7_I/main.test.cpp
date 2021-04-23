#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_I"
#define ERROR 0.000001

#include <iomanip>
#include <iostream>
#include "Mylib/Geometry/Float/area_intersection_of_circles.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace hl = haar_lib;

static constexpr double eps = ERROR;
using D                     = hl::double_eps<double, eps>;

int main() {
  hl::circle<D> c1, c2;
  std::cin >> c1.center >> c1.radius >> c2.center >> c2.radius;

  std::cout << std::fixed << std::setprecision(12) << hl::area_of_intersection_of_circles(c1, c2) << "\n";

  return 0;
}
