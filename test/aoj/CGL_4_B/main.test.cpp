#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR 0.000001

#include <iomanip>
#include <iostream>
#include "Mylib/Geometry/Float/convex_diameter.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

static constexpr double eps = ERROR;
using D                     = hl::double_eps<double, eps>;

int main() {
  int n;
  std::cin >> n;

  hl::polygon<D> g = hl::input_vector<hl::point<D>>(n);

  auto ans = hl::convex_diameter(g);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}
