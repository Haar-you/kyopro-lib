#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/convex_cut.cpp"
#include "Mylib/Geometry/Float/area_polygon.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

using D = DoubleEps<double>;
template <> double D::eps = ERROR;

int main(){
  int n; std::cin >> n;
  Polygon<D> g = input_vector<Point<D>>(n);

  int q; std::cin >> q;

  for(auto [p1, p2] : input_tuples<Point<D>, Point<D>>(q)){
    Line<D> l(p1, p2);

    Polygon<D> left, right;
    convex_cut(g, l, left, right);

    std::cout << std::fixed << std::setprecision(12) << area(left) << std::endl;
  }

  return 0;
}
