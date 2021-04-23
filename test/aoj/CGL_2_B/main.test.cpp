#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include <iostream>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_segments.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

static constexpr double eps = 1e-7;
using D                     = hl::double_eps<double, eps>;

int main() {
  int q;
  std::cin >> q;

  for (auto [p0, p1, p2, p3] : hl::input_tuples<hl::point<D>, hl::point<D>, hl::point<D>, hl::point<D>>(q)) {
    hl::segment<D> s1(p0, p1), s2(p2, p3);

    const auto s = hl::intersect_segments(s1, s2);
    if (s.is_intersected() or s.is_overlapped()) {
      std::cout << 1 << std::endl;
    } else {
      std::cout << 0 << std::endl;
    }
  }

  return 0;
}
