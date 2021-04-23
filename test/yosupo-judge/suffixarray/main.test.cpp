#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <iostream>
#include <string>
#include "Mylib/IO/join.cpp"
#include "Mylib/String/suffix_array.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string S;
  std::cin >> S;
  hl::suffix_array sa(S);

  std::cout << hl::join(sa.begin() + 1, sa.end()) << "\n";

  return 0;
}
