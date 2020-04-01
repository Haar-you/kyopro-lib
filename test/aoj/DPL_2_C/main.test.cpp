#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C"
#define ERROR 0.0001

#include <iostream>
#include <vector>
#include <iomanip>
#include "Mylib/DynamicProgramming/bitonic_tour.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int n; std::cin >> n;

  std::vector<int> x(n), y(n);
  for(int i = 0; i < n; ++i){
    std::cin >> x[i] >> y[i];
  }

  std::cout << std::fixed << std::setprecision(12) << bitonic_tour(n, x, y) << std::endl;

  return 0;
}
