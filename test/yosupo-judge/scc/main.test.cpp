#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <vector>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include "Mylib/Graph/TopologicalSort/topological_sort.cpp"
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;

  auto g = convert_to_graph<int, true>(N, input_edges<int, 0, false>(M));

  auto [scc, K] = strongly_connected_components(g);
  std::vector<std::vector<int>> ans(K);
  for(int i = 0; i < N; ++i) ans[scc[i]].push_back(i);

  Graph<int> g2(K);
  for(auto &v : g){
    for(auto &e : v){
      if(scc[e.from] != scc[e.to]) add_edge(g2, scc[e.from], scc[e.to], 1);
    }
  }

  auto ts = topological_sort(g2).value();

  std::cout << K << "\n";

  for(int i = 0; i < K; ++i){
    auto &t = ans[ts[i]];
    std::cout << t.size() << " " << join(t.begin(), t.end()) << "\n";
  }

  return 0;
}
