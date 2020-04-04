#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/closest_pair.cpp"

using D = DoubleEps<double>;
template<> double D::eps = ERROR;

int main(){
  int n; std::cin >> n;
  std::vector<Point<D>> p(n);
  for(int i = 0; i < n; ++i) std::cin >> p[i];

  auto ans = closest_pair::solve(p);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}
