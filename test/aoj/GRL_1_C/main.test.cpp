#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include <iostream>
#include "Mylib/Graph/ShortestPath/warshall_floyd.cpp"
#include "Mylib/Graph/Template/graph.cpp"

namespace hl = haar_lib;

int main() {
  int V, E;
  std::cin >> V >> E;

  hl::graph<int> g(V);
  g.read<0>(E);

  auto res = hl::warshall_floyd(g);

  if (res.has_negative_cycle) {
    std::cout << "NEGATIVE CYCLE" << std::endl;
  } else {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        if (j) std::cout << " ";
        auto &ans = res[i][j];
        if (ans) {
          std::cout << *ans;
        } else {
          std::cout << "INF";
        }
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
