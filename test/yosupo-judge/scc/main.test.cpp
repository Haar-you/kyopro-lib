#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <vector>
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;

  hl::graph<int> g(N);
  g.read<0, true, false>(M);

  auto [scc, K] = hl::strongly_connected_components(g);
  std::vector<std::vector<int>> ans(K);
  for (int i = 0; i < N; ++i) ans[scc[i]].push_back(i);

  std::cout << K << "\n";

  for (auto &t : ans) {
    std::cout << t.size() << " " << hl::join(t.begin(), t.end()) << "\n";
  }

  return 0;
}
