#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/chinese_postman_problem.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  g.read<0, false>(E);
  
  auto ans = chinese_postman_problem(g);
  std::cout << ans << std::endl;
  
  return 0;
}
