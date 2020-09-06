#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include <iostream>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/intersect_segments.cpp"
#include "Mylib/IO/input_tuples.cpp"

using D = DoubleEps<double>;
template <> double D::eps = 1e-7;

int main(){
  int q; std::cin >> q;

  for(auto [p0, p1, p2, p3] : input_tuples<Point<D>, Point<D>, Point<D>, Point<D>>(q)){
    Segment<D> s1(p0, p1), s2(p2, p3);

    if(intersect_segments::check(s1, s2).status & (intersect_segments::INTERSECTING | intersect_segments::OVERLAPPED)){
      std::cout << 1 << std::endl;
    }else{
      std::cout << 0 << std::endl;
    }
  }

  return 0;
}
