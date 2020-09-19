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
    const auto s = point_in_polygon(p, ps);
    if(s.is_inclusion()) std::cout << 2 << std::endl;
    if(s.is_on_segment()) std::cout << 1 << std::endl;
    if(s.is_outside()) std::cout << 0 << std::endl;
  }

  return 0;
}
