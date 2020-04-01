#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/chinese_postman_problem.cpp"

int main(){
  int V, E; std::cin >> V >> E;
  
  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s, t, d; std::cin >> s >> t >> d;
    add_undirected(g, s, t, d);
  }
  
  auto ans = chinese_postman_problem(g);
  std::cout << ans << std::endl;
  
  return 0;
}
