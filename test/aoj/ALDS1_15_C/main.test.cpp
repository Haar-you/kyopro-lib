#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C"

#include <iostream>
#include <vector>
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/Typical/interval_scheduling.cpp"

namespace hl = haar_lib;

int main() {
  int n;
  std::cin >> n;

  auto [left, right] = hl::input_tuple_vector<int, int>(n);
  for (auto &x : right) x += 1;

  auto ans = hl::interval_scheduling(left, right);

  std::cout << ans.size() << std::endl;

  return 0;
}
