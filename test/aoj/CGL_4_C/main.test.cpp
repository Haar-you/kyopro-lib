#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/convex_cut.cpp"
#include "Mylib/Geometry/Float/area_polygon.cpp"

using D = DoubleEps<double>;
template<> double D::eps = ERROR;

int main(){
  int n; std::cin >> n;
  Polygon<D> g(n);
  for(int i = 0; i < n; ++i) std::cin >> g[i];

  int q; std::cin >> q;

  while(q--){
    Point<D> p1, p2; std::cin >> p1 >> p2;
    Line<D> l(p1, p2);

    Polygon<D> left, right;
    convex_cut(g, l, left, right);

    std::cout << std::fixed << std::setprecision(12) << polygon_area(left) << std::endl;
  }

  return 0;
}
