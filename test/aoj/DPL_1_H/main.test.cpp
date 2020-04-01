#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_quantity.cpp"

int main(){
  int N; std::cin >> N;
  int64_t W; std::cin >> W;
  
  std::vector<int64_t> v(N), w(N);
  
  for(int i = 0; i < N; ++i){
    std::cin >> v[i] >> w[i];
  }
  
  auto ans = knapsack_small_quantity(N, W, w, v);
  
  std::cout << ans << std::endl;
  
  return 0;
}
