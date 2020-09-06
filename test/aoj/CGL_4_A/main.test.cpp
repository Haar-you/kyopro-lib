#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include <iostream>
#include <algorithm>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/convex_hull.cpp"
#include "Mylib/IO/input_vector.cpp"

using D = DoubleEps<double>;
template <> double D::eps = 1e-7;

int main(){
  int n; std::cin >> n;
  Polygon<D> ps = input_vector<Point<D>>(n);

  auto ans = convex_hull(ps);

  std::cout << ans.size() << std::endl;

  {
    std::reverse(ans.begin(), ans.end());

    int k =
      std::min_element(
        ans.begin(), ans.end(),
        [](const auto &a, const auto &b){
          return a.y < b.y or (a.y == b.y and a.x < b.x);
        }
      ) - ans.begin();

    std::rotate(ans.begin(), ans.begin() + k, ans.end());
  }

  for(auto &p : ans){
    std::cout << p.x << " " << p.y << std::endl;
  }

  return 0;
}
