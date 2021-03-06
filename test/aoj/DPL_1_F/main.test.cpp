#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F"

#include <iostream>
#include <vector>
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/Typical/knapsack_small_value.cpp"

namespace hl = haar_lib;

int main() {
  int N;
  std::cin >> N;
  int64_t W;
  std::cin >> W;

  auto [v, w] = hl::input_tuple_vector<int64_t, int64_t>(N);

  auto ans = hl::knapsack_small_value(N, W, w, v);

  std::cout << ans << std::endl;

  return 0;
}
