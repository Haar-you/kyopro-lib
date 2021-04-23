#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A"

#include <algorithm>
#include <iostream>
#include "Mylib/Algorithm/imos_1d.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main() {
  int N, T;
  std::cin >> N >> T;
  hl::imos_1d<int> imos(T + 1);

  for (auto [l, r] : hl::input_tuples<int, int>(N)) {
    imos.update(l, r, 1);
  }

  const auto res = imos.build();

  int ans = *std::max_element(res.begin(), res.end());

  std::cout << ans << std::endl;

  return 0;
}
