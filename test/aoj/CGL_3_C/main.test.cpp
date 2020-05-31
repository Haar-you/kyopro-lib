#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"

#include <iostream>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/is_point_in_polygon.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

using D = DoubleEps<double>;
template<> double D::eps = 1e-7;

int main(){
  int n; std::cin >> n;
  Polygon<D> ps = input_vector<Point<D>>(n);

  int q; std::cin >> q;
  for(auto [p] : input_tuples<Point<D>>(q)){
    switch(point_in_polygon::check(p, ps)){
    case point_in_polygon::INCLUSION: std::cout << 2 << std::endl; break;
    case point_in_polygon::ON_SEGMENT: std::cout << 1 << std::endl; break;
    case point_in_polygon::OUTSIDE: std::cout << 0 << std::endl; break;
    }
  }

  return 0;
}
