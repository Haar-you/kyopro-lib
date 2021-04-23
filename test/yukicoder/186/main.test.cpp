#define PROBLEM "https://yukicoder.me/problems/447"

#include <iostream>
#include "Mylib/Number/chinese_remainder_algorithm.cpp"

namespace hl = haar_lib;

int main() {
  int64_t x1, y1, x2, y2, x3, y3;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  if (auto res = hl::chinese_remainder_algorithm({x1, x2, x3}, {y1, y2, y3}); res) {
    const auto [r, m] = *res;
    std::cout << (r == 0 ? m : r) << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }

  return 0;
}
