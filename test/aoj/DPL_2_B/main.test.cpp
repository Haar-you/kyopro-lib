#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/chinese_postman_problem.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  auto g = convert_to_graph<int, false>(V, input_edges<int, 0, true>(E));  
  
  auto ans = chinese_postman_problem(g);
  std::cout << ans << std::endl;
  
  return 0;
}
