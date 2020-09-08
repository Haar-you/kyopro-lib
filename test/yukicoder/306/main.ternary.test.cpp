#define PROBLEM "https://yukicoder.me/problems/no/306"
#define ERROR 1e-6

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Mylib/Algorithm/Search/ternary_search_downwards.cpp"

namespace hl = haar_lib;

int main(){
  int xa, xb, ya, yb; std::cin >> xa >> ya >> xb >> yb;

  auto f =
    [&](long double p){
      return std::hypot(xa, ya - p) + std::hypot(xb, yb - p);
    };

  auto ans = hl::ternary_search_downwards<long double>(-1000, 1000, f);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}
