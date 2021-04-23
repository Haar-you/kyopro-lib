#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"

#include <iostream>
#include "Mylib/Number/Divisor/enumerate_divisors.cpp"

namespace hl = haar_lib;

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  int ans = 0;

  for (auto d : hl::enumerate_divisors(c)) {
    if (a <= d and d <= b) ++ans;
  }

  std::cout << ans << std::endl;

  return 0;
}
