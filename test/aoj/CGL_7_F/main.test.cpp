#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"
#define ERROR 0.00001

#include <algorithm>
#include <iomanip>
#include <iostream>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/tangent_of_circle.cpp"

namespace hl = haar_lib;

static constexpr double eps = ERROR;
using D                     = hl::double_eps<double, eps>;

int main() {
  hl::point<D> p;
  std::cin >> p;
  hl::circle<D> c;
  std::cin >> c.center >> c.radius;

  auto ans = hl::tangent_of_circle(c, p);

  std::sort(ans.begin(), ans.end(),
            [](const auto &a, const auto &b) {
              return a.x < b.x or (a.x == b.x and a.y < b.y);
            });

  std::cout << std::fixed << std::setprecision(12)
            << ans[0].x << " " << ans[0].y << std::endl
            << ans[1].x << " " << ans[1].y << std::endl;

  return 0;
}
