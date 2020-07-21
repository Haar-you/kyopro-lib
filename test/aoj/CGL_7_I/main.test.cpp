#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_I"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/area_intersection_of_circles.cpp"

using D = DoubleEps<double>;
template <> double D::eps = ERROR;

int main(){
  Circle<D> c1, c2;
  std::cin >> c1.center >> c1.radius >> c2.center >> c2.radius;

  std::cout << std::fixed << std::setprecision(12) << area_of_intersection_of_circles(c1, c2) << "\n";

  return 0;
}
