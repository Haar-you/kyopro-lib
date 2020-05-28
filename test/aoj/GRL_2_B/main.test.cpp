#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp"
#include "Mylib/IO/input_graph.cpp"

int main() {
  int V, E, r; std::cin >> V >> E >> r;

  auto g = convert_to_graph<int, true>(V, input_edges<int, 0, true>(E));

  auto res = ChuLiuEdmonds<int>::solve(g, r);

  int ans = 0;

  for(auto &e : res){
    ans += e.cost;
  }

  std::cout << ans << "\n";

  return 0;
}
