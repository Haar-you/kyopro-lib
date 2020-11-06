#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B"

#include <iostream>
#include <vector>
#include "Mylib/Typical/knapsack_small_weight.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

namespace hl = haar_lib;

int main(){
  int N, W; std::cin >> N >> W;

  auto [v, w] = hl::input_tuple_vector<int, int>(N);

  auto ans = hl::knapsack_small_weight(N, W, w, v);
  std::cout << ans << std::endl;

  return 0;
}
