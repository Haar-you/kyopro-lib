#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/area_polygon.cpp"

using D = DoubleEps<double>;
template<> double D::eps = 1e-7;

int main(){
  int n; std::cin >> n;

  Polygon<D> p(n);
  for(int i = 0; i < n; ++i) std::cin >> p[i];

  D ans = polygon_area(p);

  std::cout << std::fixed << std::setprecision(1) << ans << std::endl;

  return 0;
}
