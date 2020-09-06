#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/MinimumSpanningTree/prim.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int64_t> g(V);
  g.read<0, false>(E);

  auto res = prim(g);

  int64_t ans = 0;
  for(auto &e : res) ans += e.cost;
  std::cout << ans << std::endl;

  return 0;
}
