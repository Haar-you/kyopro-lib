#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"
#define ERROR 0.00000001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/intersect_segments.cpp"
#include "Mylib/IO/input_tuples.cpp"

using D = DoubleEps<double>;
template <> double D::eps = ERROR;

int main(){
  int q; std::cin >> q;

  for(auto [p0, p1, p2, p3] : input_tuples<Point<D>, Point<D>, Point<D>, Point<D>>(q)){
    Segment<D> s1(p0, p1), s2(p2, p3);

    Point<D> c = intersect_segments::check(s1, s2).crosspoints[0];

    std::cout << std::fixed << std::setprecision(12) << c.x << " " << c.y << std::endl;
  }

  return 0;
}
