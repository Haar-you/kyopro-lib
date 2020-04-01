#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_limited.cpp"

int main(){
  int N, W; std::cin >> N >> W;
  
  std::vector<int> v(N), w(N), m(N);
  for(int i = 0; i < N; ++i){
    std::cin >> v[i] >> w[i] >> m[i];
  }
  
  auto ans = knapsack_limited(N, W, w, v, m);
  std::cout << ans << std::endl;
  
  return 0;
}
