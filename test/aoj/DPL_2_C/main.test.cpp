#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C"
#define ERROR 0.0001

#include <iostream>
#include <vector>
#include <iomanip>
#include "Mylib/DynamicProgramming/bitonic_tour.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;

  auto [x, y] = hl::input_tuple_vector<int, int>(n);

  std::cout << std::fixed << std::setprecision(12) << hl::bitonic_tour(n, x, y) << std::endl;

  return 0;
}
