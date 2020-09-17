#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/is_convex.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

static constexpr double eps = 1e-7;
using D = hl::double_eps<double, eps>;

int main(){
  int n; std::cin >> n;

  hl::polygon<D> p = hl::input_vector<hl::point<D>>(n);

  std::cout << (hl::is_convex(p) ? 1 : 0) << std::endl;

  return 0;
}
