#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/inscribed_circle_of_triangle.cpp"

namespace hl = haar_lib;

using D = hl::DoubleEps<double>;
template <> double D::eps = ERROR;

int main(){
  hl::Point<D> a, b, c; std::cin >> a >> b >> c;

  auto ans = hl::inscribed_circle_of_triangle(a, b, c);
  std::cout << std::fixed << std::setprecision(12)
            << ans.center.x << " "
            << ans.center.y << " "
            << ans.radius << "\n";

  return 0;
}
