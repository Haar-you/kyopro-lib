#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/travelling_salesman_problem.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  g.read<0>(E);
  
  std::cout << travelling_salesman_problem(g, 0).value_or(-1) << std::endl;
  
  return 0;
}
