#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/is_convex.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

using D = hl::DoubleEps<double>;
template <> double D::eps = 1e-7;

int main(){
  int n; std::cin >> n;

  hl::Polygon<D> p = hl::input_vector<hl::Point<D>>(n);

  std::cout << (hl::is_convex(p) ? 1 : 0) << std::endl;

  return 0;
}
