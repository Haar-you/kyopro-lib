#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/convex_diameter.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

using D = hl::DoubleEps<double>;
template <> double D::eps = ERROR;

int main(){
  int n; std::cin >> n;

  hl::Polygon<D> g = hl::input_vector<hl::Point<D>>(n);

  auto ans = hl::convex_diameter(g);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}
