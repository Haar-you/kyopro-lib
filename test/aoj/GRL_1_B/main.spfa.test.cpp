#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#include "Mylib/Graph/ShortestPath/spfa.cpp"
#include "Mylib/Graph/Template/graph.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int V, E, r;
  std::cin >> V >> E >> r;

  hl::graph<int64_t> g(V);
  g.read<0>(E);

  auto res = hl::spfa(g, r);

  if (res) {
    for (auto &x : res.value()) {
      if (x)
        std::cout << x.value() << "\n";
      else
        std::cout << "INF\n";
    }
  } else {
    std::cout << "NEGATIVE CYCLE\n";
  }

  return 0;
}
