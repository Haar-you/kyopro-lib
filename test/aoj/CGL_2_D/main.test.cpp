#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#define ERROR 0.00000001

#include <iomanip>
#include <iostream>
#include "Mylib/Geometry/Float/distance_segments.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

static constexpr double eps = ERROR;
using D                     = hl::double_eps<double, eps>;

int main() {
  int q;
  std::cin >> q;

  for (auto [p0, p1, p2, p3] : hl::input_tuples<hl::point<D>, hl::point<D>, hl::point<D>, hl::point<D>>(q)) {
    hl::segment<D> s1(p0, p1), s2(p2, p3);

    D ans = hl::distance_segments(s1, s2);

    std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  }

  return 0;
}
