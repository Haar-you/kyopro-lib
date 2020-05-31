#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circle_line.cpp"
#include "Mylib/IO/input_tuples.cpp"

using D = DoubleEps<double>;
template<> double D::eps = 1e-7;

int main(){
  Circle<D> c;
  std::cin >> c.center >> c.radius;

  int q; std::cin >> q;

  for(auto [p0, p1] : input_tuples<Point<D>, Point<D>>(q)){
    Line<D> l(p0, p1);

    auto [s, ans] = intersect_circle_line::check(c, l);
    
    std::sort(ans.begin(), ans.end(), [](const auto &a, const auto &b){return a.x < b.x or (a.x == b.x and a.y < b.y);});

    std::cout << std::fixed << std::setprecision(12);

    if(s == intersect_circle_line::TANGENT){
      std::cout << ans[0].x << " " << ans[0].y << " ";
      std::cout << ans[0].x << " " << ans[0].y << std::endl;
    }else if(s == intersect_circle_line::CROSSED){
      std::cout << ans[0].x << " " << ans[0].y << " ";
      std::cout << ans[1].x << " " << ans[1].y << std::endl;
    }
  }

  return 0;
}
