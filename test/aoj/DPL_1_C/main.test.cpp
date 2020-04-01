#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_unlimited.cpp"

int main(){
  int N, W; std::cin >> N >> W;
  std::vector<int> v(N), w(N);
  
  for(int i = 0; i < N; ++i){
    std::cin >> v[i] >> w[i];
  }
  
  auto ans = knapsack_unlimited(N, W, w, v);
  
  std::cout << ans << std::endl;
  
  return 0;
}
