#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

static constexpr double eps = ERROR;
using D = hl::double_eps<double, eps>;

int main(){
  int n; std::cin >> n;
  int r; std::cin >> r;

  hl::circle<D> c(hl::point<D>(0, 0), r);

  hl::polygon<D> p = hl::input_vector<hl::point<D>>(n);

  auto ans = hl::area_intersection_of_circle_and_polygon(c, p);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}
