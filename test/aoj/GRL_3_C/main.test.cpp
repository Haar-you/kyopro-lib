#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int V, E; std::cin >> V >> E;

  hl::Graph<int> g(V);
  g.read<0, true, false>(E);

  auto scc = hl::strongly_connected_components(g).first;

  int q; std::cin >> q;

  for(auto [u, v] : hl::input_tuples<int, int>(q)){
    std::cout << (scc[u] == scc[v]) << std::endl;
  }

  return 0;
}
