#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/travelling_salesman_problem.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  auto g = convert_to_graph<int, true>(V, input_edges<int, 0, true>(E));
  
  std::cout << travelling_salesman_problem(g, 0).value_or(-1) << std::endl;
  
  return 0;
}
