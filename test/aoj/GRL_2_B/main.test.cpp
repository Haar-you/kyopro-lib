#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp"

namespace hl = haar_lib;

int main(){
  int V, E, r; std::cin >> V >> E >> r;

  hl::Graph<int> g(V);
  g.read<0>(E);

  auto res = hl::chu_liu_edmonds(g, r);

  int ans = 0;

  for(auto &e : res){
    ans += e.cost;
  }

  std::cout << ans << "\n";

  return 0;
}
