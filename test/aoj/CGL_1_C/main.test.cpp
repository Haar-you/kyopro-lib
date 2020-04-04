#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include <iostream>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

using D = DoubleEps<double>;
template<> double D::eps = 1e-7;

int main(){
  Point<D> p0, p1; std::cin >> p0 >> p1;

  int q; std::cin >> q;

  while(q--){
    Point<D> p2; std::cin >> p2;

    switch(ccw::ccw(p0, p1, p2)){
    case ccw::ONLINE_BACK: std::cout << "ONLINE_BACK" << std::endl; break;
    case ccw::COUNTER_CLOCKWISE: std::cout << "COUNTER_CLOCKWISE" << std::endl; break;
    case ccw::ON_SEGMENT: std::cout << "ON_SEGMENT" << std::endl; break;
    case ccw::CLOCKWISE: std::cout << "CLOCKWISE" << std::endl; break;
    case ccw::ONLINE_FRONT: std::cout << "ONLINE_FRONT" << std::endl; break;
    }
  }
  
  return 0;
}
