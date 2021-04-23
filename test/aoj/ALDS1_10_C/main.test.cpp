#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include <iostream>
#include <string>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/String/longest_common_subsequence.cpp"

namespace hl = haar_lib;

int main() {
  int q;
  std::cin >> q;

  for (auto [x, y] : hl::input_tuples<std::string, std::string>(q)) {
    std::cout << hl::lcs(x, y) << std::endl;
  }

  return 0;
}
