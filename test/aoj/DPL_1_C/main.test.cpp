#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_unlimited.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

int main(){
  int N, W; std::cin >> N >> W;

  auto [v, w] = input_tuple_vector<int, int>(N);

  auto ans = knapsack_unlimited(N, W, w, v);
  std::cout << ans << std::endl;

  return 0;
}
