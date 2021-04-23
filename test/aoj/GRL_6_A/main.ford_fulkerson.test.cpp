#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <climits>
#include <iostream>
#include "Mylib/Graph/Flow/ford_fulkerson.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main() {
  int V, E;
  std::cin >> V >> E;

  hl::ford_fulkerson<int> f(V);

  for (auto [s, t, c] : hl::input_tuples<int, int, int>(E)) {
    f.add_edge(s, t, c);
  }

  auto ans = f.max_flow(0, V - 1);
  std::cout << ans << std::endl;

  return 0;
}
