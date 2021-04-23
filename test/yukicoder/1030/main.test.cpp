#define PROBLEM "https://yukicoder.me/problems/no/1030"

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include "Mylib/AlgebraicStructure/Monoid/max.cpp"
#include "Mylib/AlgebraicStructure/Monoid/maybe.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

struct lca_semigroup {
  using value_type = int;
  static std::function<int(int, int)> lca;
  value_type operator()(value_type a, value_type b) const {
    return lca(a, b);
  }
};

std::function<int(int, int)> lca_semigroup::lca;

int main() {
  int N, K, Q;
  std::cin >> N >> K >> Q;

  auto C = hl::input_vector<int>(N);
  auto A = hl::input_vector<int>(K);
  for (auto &x : A) --x;

  hl::tree<int> tree(N);
  tree.read<1, false, false>(N - 1);

  hl::hl_decomposition<int> hld(tree, 0);
  lca_semigroup::lca = [&](int a, int b) { return hld.lca(a, b); };

  hl::segment_tree<hl::max_monoid<int>> seg1(N);
  for (int i = 0; i < N; ++i) {
    seg1.set(hld.get_id(i), {C[i]});
  }

  hl::segment_tree<hl::maybe_monoid<lca_semigroup>> seg2(K);
  seg2.init_with_vector(A);

  for (auto [T] : hl::input_tuples<int>(Q)) {
    if (T == 1) {
      int X, Y;
      std::cin >> X >> Y;
      --X;
      --Y;

      seg2.set(X, Y);
    } else {
      int L, R;
      std::cin >> L >> R;

      int lca = *seg2.fold(L - 1, R);
      int ans = 0;

      for (auto [l, r, d] : hld.path_query_vertex(0, lca)) {
        ans = std::max(ans, seg1.fold(l, r).value());
      }

      std::cout << ans << "\n";
    }
  }

  return 0;
}
