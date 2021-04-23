#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR 0.00000001

#include <iomanip>
#include <iostream>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/reflection.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

static constexpr double eps = ERROR;
using D                     = hl::double_eps<double, eps>;

int main() {
  hl::point<D> p1, p2;
  std::cin >> p1 >> p2;
  hl::line<D> l(p1, p2);

  int q;
  std::cin >> q;

  for (auto [p] : hl::input_tuples<hl::point<D>>(q)) {
    auto ans = hl::reflection(l, p);
    std::cout << std::fixed << std::setprecision(12) << ans.x << " " << ans.y << std::endl;
  }

  return 0;
}
