#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/travelling_salesman_problem.cpp"

namespace hl = haar_lib;

int main(){
  int V, E; std::cin >> V >> E;

  hl::Graph<int> g(V);
  g.read<0>(E);

  std::cout << hl::travelling_salesman_problem(g, 0).value_or(-1) << std::endl;

  return 0;
}
