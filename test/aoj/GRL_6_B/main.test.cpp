#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <iostream>
#include "Mylib/Graph/Flow/minimum_cost_flow.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main() {
  int V, E, F;
  std::cin >> V >> E >> F;

  hl::minimum_cost_flow<int, int> f(V);

  for (auto [u, v, c, d] : hl::input_tuples<int, int, int, int>(E)) {
    f.add_edge(u, v, c, d);
  }

  auto [flow, ret] = f.min_cost_flow(0, V - 1, F);
  if (flow == F) {
    std::cout << ret << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }

  return 0;
}
