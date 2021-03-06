#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR 0.000001

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circle_line.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

static constexpr double eps = ERROR;
using D                     = hl::double_eps<double, eps>;

int main() {
  hl::circle<D> c;
  std::cin >> c.center >> c.radius;

  int q;
  std::cin >> q;

  for (auto [p0, p1] : hl::input_tuples<hl::point<D>, hl::point<D>>(q)) {
    hl::line<D> l(p0, p1);

    const auto s = hl::intersect_circle_line(c, l);
    auto ans     = s.crosspoints;

    std::sort(
        ans.begin(), ans.end(),
        [](const auto &a, const auto &b) { return a.x < b.x or (a.x == b.x and a.y < b.y); });

    std::cout << std::fixed << std::setprecision(12);

    if (s.is_tangent()) {
      std::cout << ans[0].x << " " << ans[0].y << " ";
      std::cout << ans[0].x << " " << ans[0].y << std::endl;
    } else if (s.is_crossed()) {
      std::cout << ans[0].x << " " << ans[0].y << " ";
      std::cout << ans[1].x << " " << ans[1].y << std::endl;
    }
  }

  return 0;
}
