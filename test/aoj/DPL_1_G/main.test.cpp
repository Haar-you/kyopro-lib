#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G"

#include <iostream>
#include <vector>
#include "Mylib/Typical/knapsack_limited.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

namespace hl = haar_lib;

int main(){
  int N, W; std::cin >> N >> W;

  auto [v, w, m] = hl::input_tuple_vector<int, int, int>(N);

  auto ans = hl::knapsack_limited(N, W, w, v, m);
  std::cout << ans << std::endl;

  return 0;
}
