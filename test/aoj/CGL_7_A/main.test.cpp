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

  switch(hl::intersect_circles::check(c1, c2).status){
  case hl::intersect_circles::INSIDE: std::cout << 0 << std::endl; break;
  case hl::intersect_circles::INSCRIBED: std::cout << 1 << std::endl; break;
  case hl::intersect_circles::INTERSECT: std::cout << 2 << std::endl; break;
  case hl::intersect_circles::CIRCUMSCRIBED: std::cout << 3 << std::endl; break;
  case hl::intersect_circles::OUTSIDE: std::cout << 4 << std::endl; break;
  default: break;
  }

  return 0;
}

