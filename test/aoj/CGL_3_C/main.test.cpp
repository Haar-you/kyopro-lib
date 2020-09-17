#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"

#include <iostream>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/is_point_in_polygon.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

static constexpr double eps = 1e-7;
using D = hl::double_eps<double, eps>;

int main(){
  int n; std::cin >> n;
  hl::polygon<D> ps = hl::input_vector<hl::point<D>>(n);

  int q; std::cin >> q;
  for(auto [p] : hl::input_tuples<hl::point<D>>(q)){
    switch(hl::point_in_polygon::check(p, ps)){
    case hl::point_in_polygon::INCLUSION: std::cout << 2 << std::endl; break;
    case hl::point_in_polygon::ON_SEGMENT: std::cout << 1 << std::endl; break;
    case hl::point_in_polygon::OUTSIDE: std::cout << 0 << std::endl; break;
    }
  }

  return 0;
}
