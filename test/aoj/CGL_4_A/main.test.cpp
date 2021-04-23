#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include <algorithm>
#include <iostream>
#include "Mylib/Geometry/Float/convex_hull.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

static constexpr double eps = 1e-7;
using D                     = hl::double_eps<double, eps>;

int main() {
  int n;
  std::cin >> n;
  hl::polygon<D> ps = hl::input_vector<hl::point<D>>(n);

  auto ans = hl::convex_hull(ps);

  std::cout << ans.size() << std::endl;

  {
    std::reverse(ans.begin(), ans.end());

    int k =
        std::min_element(
            ans.begin(), ans.end(),
            [](const auto &a, const auto &b) {
              return a.y < b.y or (a.y == b.y and a.x < b.x);
            }) -
        ans.begin();

    std::rotate(ans.begin(), ans.begin() + k, ans.end());
  }

  for (auto &p : ans) {
    std::cout << p.x << " " << p.y << std::endl;
  }

  return 0;
}
