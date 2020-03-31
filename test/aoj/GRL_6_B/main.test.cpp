#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <iostream>
#include "Mylib/Graph/Flow/minimum_cost_flow.cpp"

int main(){
  int V, E, F; std::cin >> V >> E >> F;

  MinimumCostFlow<int, int> f(V);

  for(int i = 0; i < E; ++i){
    int u, v, c, d; std::cin >> u >> v >> c >> d;

    f.add_edge(u, v, c, d);
  }

  int ret;
  
  if(f.solve(0, V-1, F, ret) == F){
    std::cout << ret << std::endl;
  }else{
    std::cout << -1 << std::endl;
  }
  
  return 0;
}
