#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  auto g = convert_to_graph<int, true>(V, input_edges<int, 0, false>(E));

  auto scc = strongly_connected_components(g).first;

  int q; std::cin >> q;

  for(auto [u, v] : input_tuples<int, int>(q)){
    std::cout << (scc[u] == scc[v]) << std::endl;
  }

  return 0;
}
