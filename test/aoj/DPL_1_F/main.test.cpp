#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_value.cpp"

int main(){
  int N; std::cin >> N;
  int64_t W; std::cin >> W;
  
  std::vector<int64_t> v(N), w(N);
  
  for(int i = 0; i < N; ++i){
    std::cin >> v[i] >> w[i];
  }
  
  auto ans = knapsack_small_value(N, W, w, v);
  
  std::cout << ans << std::endl;
  
  return 0;
}
