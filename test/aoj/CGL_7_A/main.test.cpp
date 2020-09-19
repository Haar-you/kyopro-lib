#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"

#include <iostream>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circles.cpp"

namespace hl = haar_lib;

static constexpr double eps = 1e-7;
using D = hl::double_eps<double, eps>;

int main(){
  hl::circle<D> c1, c2;
  std::cin >> c1.center >> c1.radius >> c2.center >> c2.radius;

  const auto s = hl::intersect_circles(c1, c2);

  if(s.is_inside()) std::cout << 0 << std::endl;
  if(s.is_inscribed()) std::cout << 1 << std::endl;
  if(s.is_intersected()) std::cout << 2 << std::endl;
  if(s.is_circumscribed()) std::cout << 3 << std::endl;
  if(s.is_outside()) std::cout << 4 << std::endl;

  return 0;
}

