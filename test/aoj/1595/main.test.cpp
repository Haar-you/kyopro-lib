#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/rerooting.cpp"

namespace hl = haar_lib;

int main() {
  int N;
  std::cin >> N;

  hl::tree<int> tree(N);
  tree.read<1, false, false>(N - 1);

  auto r = hl::rerooting<int>(
      tree,
      0,
      [](const auto &a, const auto &b) {
        return std::max(a, b);
      },
      [](const auto &a, const auto &) {
        return a + 1;
      },
      [](const auto &a, int) {
        return a;
      });

  for (auto &x : r) {
    std::cout << 2 * (N - 1) - x << std::endl;
  }

  return 0;
}
