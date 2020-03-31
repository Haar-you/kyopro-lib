#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <vector>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include "Mylib/Graph/TopologicalSort/topological_sort.cpp"

int main(){
  int N, M; scanf("%d%d", &N, &M);

  Graph<int> g(N);
  for(int i = 0; i < M; ++i){
    int a, b; scanf("%d%d", &a, &b);
    add_edge(g, a, b, 1);
  }

  auto scc = SCC(g);
  int K = scc.scc_size;
  std::vector<std::vector<int>> ans(K);
  for(int i = 0; i < N; ++i) ans[scc[i]].push_back(i);

  Graph<int> g2(K);
  for(auto &v : g){
    for(auto &e : v){
      if(scc[e.from] != scc[e.to]) add_edge(g2, scc[e.from], scc[e.to], 1);
    }
  }

  auto ts = topological_sort(g2).value();

  printf("%d\n", K);

  for(int i = 0; i < K; ++i){
    auto &t = ans[ts[i]];

    printf("%d", t.size());
    for(auto &x : t){
      printf(" %d", x);
    }
    printf("\n");
  }

  return 0;
}
