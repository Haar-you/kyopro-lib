#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_quantity.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

int main(){
  int N; std::cin >> N;
  int64_t W; std::cin >> W;

  auto [v, w] = input_tuple_vector<int64_t, int64_t>(N);

  auto ans = knapsack_small_quantity(N, W, w, v);

  std::cout << ans << std::endl;

  return 0;
}
