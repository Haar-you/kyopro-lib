#define PROBLEM "https://yukicoder.me/problems/no/306"
#define ERROR 1e-6

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Mylib/Algorithm/Search/golden_section_search_downwards.cpp"


int main(){
  int xa, xb, ya, yb; std::cin >> xa >> ya >> xb >> yb;
  
  auto f =
    [&](long double p){
      return std::hypot(xa, ya-p) + std::hypot(xb, yb-p);
    };

  auto ans = golden_section_search_downwards<long double>(-1000, 1000, f);
  
  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  
  return 0;
}
