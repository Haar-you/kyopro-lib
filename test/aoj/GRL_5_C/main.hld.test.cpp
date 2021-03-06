#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/lca_hld.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

namespace hl = haar_lib;

int main() {
  int n;
  std::cin >> n;

  hl::tree<int> tree(n);
  for (auto [i, k] : hl::input_tuples_with_index<int>(n)) {
    for (auto [c] : hl::input_tuples<int>(k)) {
      tree.add_edge(i, c, 1);
    }
  }

  auto lca = hl::lowest_common_ancestor_hld(tree, 0);

  int q;
  std::cin >> q;

  for (auto [u, v] : hl::input_tuples<int, int>(q)) {
    std::cout << lca(u, v) << std::endl;
  }

  return 0;
}
