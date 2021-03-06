#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include <iostream>
#include "Mylib/Graph/Cycle/detect_cycle.cpp"
#include "Mylib/Graph/Template/graph.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  hl::graph<int> g(N);
  g.read<0, true, false>(M);

  auto res = hl::detect_cycle(g);

  if (res) {
    std::cout << (*res).size() << "\n";
    for (auto &e : *res) {
      std::cout << e.index << "\n";
    }
  } else {
    std::cout << -1 << "\n";
  }

  return 0;
}
