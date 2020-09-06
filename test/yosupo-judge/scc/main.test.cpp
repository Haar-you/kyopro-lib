#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include "Mylib/Graph/TopologicalSort/topological_sort.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;

  Graph<int> g(N);
  g.read<0, true, false>(M);

  auto [scc, K] = strongly_connected_components(g);
  std::vector<std::vector<int>> ans(K);
  for(int i = 0; i < N; ++i) ans[scc[i]].push_back(i);

  Graph<int> g2(K);
  for(auto &v : g){
    for(auto &e : v){
      if(scc[e.from] != scc[e.to]) g2.add_edge(scc[e.from], scc[e.to], 1);
    }
  }

  auto ts = topological_sort(g2).value();

  std::cout << K << "\n";

  for(auto i : ts){
    auto &t = ans[i];
    std::cout << t.size() << " " << join(t.begin(), t.end()) << "\n";
  }

  return 0;
}
