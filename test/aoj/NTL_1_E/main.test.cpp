#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <iostream>
#include "Mylib/Number/extended_gcd.cpp"

namespace hl = haar_lib;

int main() {
  int a, b;
  std::cin >> a >> b;

  int x, y;
  std::tie(std::ignore, x, y) = hl::ext_gcd(a, b);

  std::cout << x << " " << y << std::endl;

  return 0;
}
