#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/MinimumSpanningTree/kruskal.cpp"

int main(){
  int V, E; std::cin >> V >> E;
  
  Graph<int64_t> g(V);
  for(int i = 0; i < E; ++i){
    int s, t, d; std::cin >> s >> t >> d;
    add_undirected(g, s, t, (int64_t)d);
  }

  auto res = kruskal(g);

  int64_t ans = 0;
  for(auto &e : res) ans += e.cost; 
  std::cout << ans << std::endl;

  return 0;
}
