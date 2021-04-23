#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D"

#include <iostream>
#include <string>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/String/suffix_array.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string T;
  std::cin >> T;
  int Q;
  std::cin >> Q;

  auto sa = hl::suffix_array(T);

  for (auto [P] : hl::input_tuples<std::string>(Q)) {
    bool ans = sa.upper_bound(P) - sa.lower_bound(P) > 0;
    std::cout << ans << "\n";
  }

  return 0;
}
