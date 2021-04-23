#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include <iostream>
#include <vector>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Number/binary_gcd.cpp"

namespace hl = haar_lib;

int main() {
  int n;
  std::cin >> n;

  auto a = hl::input_vector<int>(n);

  int l = 1;
  for (auto x : a) {
    l = l / hl::binary_gcd(l, x) * x;
  }

  std::cout << l << "\n";

  return 0;
}
