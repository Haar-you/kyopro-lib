#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/common_tangent_of_circles.cpp"

namespace hl = haar_lib;

using D = hl::DoubleEps<double>;
template <> double D::eps = ERROR;

int main(){
  hl::Circle<D> c1, c2;
  std::cin >> c1.center >> c1.radius >> c2.center >> c2.radius;

  auto ans = hl::common_tangent_of_circles(c1, c2);

  std::sort(ans.begin(), ans.end(),
            [](const auto &a, const auto &b){
              return a.x < b.x or (a.x == b.x and a.y < b.y);
            });

  std::cout << std::fixed << std::setprecision(12);

  for(auto &p : ans){
    std::cout << p.x << " " << p.y << std::endl;
  }

  return 0;
}
