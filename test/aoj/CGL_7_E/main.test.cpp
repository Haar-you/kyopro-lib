#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E"
#define ERROR 0.000001

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circles.cpp"

namespace hl = haar_lib;

static constexpr double eps = ERROR;
using D                     = hl::double_eps<double, eps>;

int main() {
  hl::circle<D> c1, c2;
  std::cin >> c1.center >> c1.radius >> c2.center >> c2.radius;

  auto ans = hl::intersect_circles(c1, c2).crosspoints;

  std::sort(
      ans.begin(), ans.end(),
      [](const auto &a, const auto &b) { return a.x < b.x or (a.x == b.x and a.y < b.y); });

  std::cout << std::fixed << std::setprecision(12);

  if (ans.size() == 1) {
    std::cout << ans[0].x << " " << ans[0].y << " ";
    std::cout << ans[0].x << " " << ans[0].y << std::endl;
  } else {
    std::cout << ans[0].x << " " << ans[0].y << " ";
    std::cout << ans[1].x << " " << ans[1].y << std::endl;
  }

  return 0;
}
