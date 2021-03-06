#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <algorithm>
#include <iostream>
#include "Mylib/Graph/GraphUtils/articulation_points.cpp"
#include "Mylib/Graph/Template/graph.cpp"

namespace hl = haar_lib;

int main() {
  int V, E;
  std::cin >> V >> E;

  hl::graph<int> g(V);
  g.read<0, false, false>(E);

  auto ans = hl::articulation_points(g);
  std::sort(ans.begin(), ans.end());

  for (auto x : ans) std::cout << x << std::endl;

  return 0;
}
