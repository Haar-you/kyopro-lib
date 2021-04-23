#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <iostream>
#include <vector>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Typical/range_inversions_query.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  auto A = hl::input_vector<int>(N);

  hl::range_inversions_query riq(A);

  for (auto [l, r] : hl::input_tuples<int, int>(Q)) {
    riq.add(l, r);
  }

  auto ans = riq.solve();

  for (auto x : ans) {
    std::cout << x << "\n";
  }

  return 0;
}
