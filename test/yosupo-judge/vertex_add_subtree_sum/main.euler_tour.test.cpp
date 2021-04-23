#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/Graph/TreeUtils/euler_tour_vertex.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  auto a = hl::input_vector<int64_t>(N);

  hl::tree<int> tree(N);
  for (int i = 1; i < N; ++i) {
    int p;
    std::cin >> p;
    tree.add_edge(p, i, 1);
  }

  auto seg = hl::segment_tree<hl::sum_monoid<int64_t>>(N);
  auto et  = hl::euler_tour_vertex(tree, 0);

  for (int i = 0; i < N; ++i) {
    et.point_query(
        i,
        [&](int j) {
          seg.set(j, a[i]);
        });
  }

  for (auto [t, u] : hl::input_tuples<int, int>(Q)) {
    if (t == 0) {
      int x;
      std::cin >> x;

      et.point_query(
          u,
          [&](int j) {
            seg.update(j, x);
          });
    } else {
      int64_t ans = 0;
      et.subtree_query(
          u,
          [&](int l, int r) {
            ans += seg.fold(l, r);
          });

      std::cout << ans << "\n";
    }
  }

  return 0;
}
