#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR 0.00000001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/reflection.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using D = hl::DoubleEps<double>;
template <> double D::eps = ERROR;

int main(){
  hl::Point<D> p1, p2; std::cin >> p1 >> p2;
  hl::Line<D> l(p1, p2);

  int q; std::cin >> q;

  for(auto [p] : hl::input_tuples<hl::Point<D>>(q)){
    auto ans = hl::reflection(l, p);
    std::cout << std::fixed << std::setprecision(12) << ans.x << " " << ans.y << std::endl;
  }

  return 0;
}
