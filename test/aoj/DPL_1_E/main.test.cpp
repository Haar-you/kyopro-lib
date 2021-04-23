#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E"

#include <iostream>
#include <string>
#include "Mylib/String/levenshtein_distance.cpp"

namespace hl = haar_lib;

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;

  auto ans = hl::levenshtein_distance(s1, s2);

  std::cout << ans << std::endl;

  return 0;
}
