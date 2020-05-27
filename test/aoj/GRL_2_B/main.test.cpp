#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp"

int main() {
  int V, E, r; std::cin >> V >> E >> r;

  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s, t, w; std::cin >> s >> t >> w;
    add_edge(g, s, t, w);
  }

  auto res = ChuLiuEdmonds<int>::solve(g, r);

  int ans = 0;

  for(auto &e : res){
    ans += e.cost;
  }

  std::cout << ans << "\n";

  return 0;
}
