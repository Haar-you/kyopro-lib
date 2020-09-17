#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/closest_pair.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

static constexpr double eps = ERROR;
using D = hl::double_eps<double, eps>;

int main(){
  int n; std::cin >> n;

  auto p = hl::input_vector<hl::point<D>>(n);

  auto ans = hl::closest_pair(p);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}
