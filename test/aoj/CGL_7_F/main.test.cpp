#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/tangent_of_circle.cpp"

using D = DoubleEps<double>;
template <> double D::eps = ERROR;

int main(){
  Point<D> p; std::cin >> p;
  Circle<D> c; std::cin >> c.center >> c.radius;

  auto ans = tangent_of_circle(c, p);

  std::sort(ans.begin(), ans.end(),
            [](const auto &a, const auto &b){
              return a.x < b.x or (a.x == b.x and a.y < b.y);
            });

  std::cout << std::fixed << std::setprecision(12)
            << ans[0].x << " " << ans[0].y << std::endl
            << ans[1].x << " " << ans[1].y << std::endl;

  return 0;
}

