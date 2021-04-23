#define PROBLEM "https://yukicoder.me/problems/no/499"

#include <algorithm>
#include <iostream>
#include "Mylib/IO/join.cpp"
#include "Mylib/Misc/convert_base.cpp"

namespace hl = haar_lib;

int main() {
  int N;
  std::cin >> N;

  auto res = hl::convert_base_to(N, 7);

  std::cout << hl::join(res.begin(), res.end(), "") << "\n";

  return 0;
}
