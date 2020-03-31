#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s, t; std::cin >> s >> t;
    add_edge(g, s, t, 1);
  }

  auto scc = SCC(g);

  int q; std::cin >> q;

  for(int i = 0; i < q; ++i){
    int u, v; std::cin >> u >> v;

    std::cout << (scc[u] == scc[v]) << std::endl;
  }

  return 0;
}
