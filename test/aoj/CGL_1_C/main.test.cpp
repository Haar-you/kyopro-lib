#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include <iostream>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

static constexpr double eps = 1e-7;
using D = hl::double_eps<double, eps>;

int main(){
  hl::point<D> p0, p1; std::cin >> p0 >> p1;

  int q; std::cin >> q;

  for(auto [p2] : hl::input_tuples<hl::point<D>>(q)){
    switch(hl::ccw::ccw(p0, p1, p2)){
    case hl::ccw::ONLINE_BACK: std::cout << "ONLINE_BACK" << std::endl; break;
    case hl::ccw::COUNTER_CLOCKWISE: std::cout << "COUNTER_CLOCKWISE" << std::endl; break;
    case hl::ccw::ON_SEGMENT: std::cout << "ON_SEGMENT" << std::endl; break;
    case hl::ccw::CLOCKWISE: std::cout << "CLOCKWISE" << std::endl; break;
    case hl::ccw::ONLINE_FRONT: std::cout << "ONLINE_FRONT" << std::endl; break;
    }
  }

  return 0;
}
