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
    const auto s = hl::check_ccw(p0, p1, p2);
    if(s.is_online_back()) std::cout << "ONLINE_BACK" << std::endl;
    if(s.is_counter_clockwise()) std::cout << "COUNTER_CLOCKWISE" << std::endl;
    if(s.is_on_segment()) std::cout << "ON_SEGMENT" << std::endl;
    if(s.is_clockwise()) std::cout << "CLOCKWISE" << std::endl;
    if(s.is_online_front()) std::cout << "ONLINE_FRONT" << std::endl;
  }

  return 0;
}
