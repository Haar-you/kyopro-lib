#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <iostream>
#include "Mylib/Algorithm/cumulative_sum_1d.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  auto a = hl::input_vector<int64_t>(N);

  auto c = hl::cumulative_sum_1d_builder<int64_t>(N).update(a).build();

  for (auto [l, r] : hl::input_tuples<int, int>(Q)) {
    std::cout << c.fold(l, r) << "\n";
  }

  return 0;
}
