#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_weight.cpp"

int main(){
  int N, W; std::cin >> N >> W;
  
  std::vector<int> w(N), v(N);
  for(int i = 0; i < N; ++i){
    std::cin >> v[i] >> w[i];
  }
  
  auto ans = knapsack_small_weight(N, W, w, v);
  std::cout << ans << std::endl;
  
  return 0;
}
