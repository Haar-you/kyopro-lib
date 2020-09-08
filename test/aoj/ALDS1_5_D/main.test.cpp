#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include <iostream>
#include <vector>
#include <functional>
#include "Mylib/Algorithm/InversionNumber/inversion_number.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

int main(){
  int n; std::cin >> n;

  auto a = hl::input_vector<int>(n);

  auto ans = hl::inversion_number(a, std::greater<int>());
  std::cout << ans << std::endl;

  return 0;
}
