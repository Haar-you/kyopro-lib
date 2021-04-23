#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"

#include <iomanip>
#include <iostream>
#include "Mylib/Geometry/Float/area_polygon.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

static constexpr double eps = 1e-7;
using D                     = hl::double_eps<double, eps>;

int main() {
  int n;
  std::cin >> n;

  hl::polygon<D> p = hl::input_vector<hl::point<D>>(n);

  D ans = hl::area(p);

  std::cout << std::fixed << std::setprecision(1) << ans << std::endl;

  return 0;
}
