#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"

#include "Mylib/Combinatorics/binomial_coefficient.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int T, m;
  std::cin >> T >> m;

  hl::binomial_coefficient c(m);

  for (auto [n, k] : hl::input_tuples<int64_t, int64_t>(T)) {
    std::cout << c(n, k) << "\n";
  }

  return 0;
}
