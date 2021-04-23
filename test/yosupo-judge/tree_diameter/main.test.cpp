#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/tree_diameter.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N;
  std::cin >> N;

  hl::tree<int64_t> tree(N);
  tree.read<0, false>(N - 1);

  auto [cost, path] = hl::tree_diameter(tree);

  std::cout
      << cost << " " << path.size() << "\n"
      << hl::join(path.begin(), path.end()) << "\n";

  return 0;
}
