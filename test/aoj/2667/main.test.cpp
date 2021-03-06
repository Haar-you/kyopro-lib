#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#include <iostream>
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using sum = hl::sum_monoid<int64_t>;

int main() {
  int N, Q;
  std::cin >> N >> Q;

  hl::tree<int> tree(N);
  tree.read<0, false, false>(N - 1);

  auto hld = hl::hl_decomposition(tree, 0);
  hl::lazy_segment_tree<hl::add_sum<sum, sum>> seg(N);

  for (auto [c] : hl::input_tuples<int>(Q)) {
    if (c == 0) {
      int u, v;
      std::cin >> u >> v;

      int64_t ans = 0;
      for (auto [l, r] : hld.path_query_edge(u, v)) {
        ans += seg.fold(l, r);
      }
      std::cout << ans << std::endl;
    } else {
      int v, x;
      std::cin >> v >> x;

      auto [l, r] = hld.subtree_query_edge(v);
      seg.update(l, r, x);
    }
  }

  return 0;
}
