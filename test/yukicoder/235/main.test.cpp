#define PROBLEM "https://yukicoder.me/problems/no/235"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp"
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Utils/sort_simultaneously.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N;
  std::cin >> N;
  auto S = hl::input_vector<mint>(N);
  auto C = hl::input_vector<mint>(N);

  hl::tree<int> tr(N);
  tr.read<1, false, false>(N - 1);

  auto hld = hl::hl_decomposition(tr, 0);

  hl::sort_simultaneously(
      [&](int i, int j) { return hld.get_id(i) < hld.get_id(j); },
      S, C);

  auto seg = hl::lazy_segment_tree_with_coefficients<mint>(N, C);
  seg.init_with_vector(S);

  int Q;
  std::cin >> Q;

  for (auto [type] : hl::input_tuples<int>(Q)) {
    if (type == 0) {
      int X, Y, Z;
      std::cin >> X >> Y >> Z;
      --X, --Y;
      for (auto [l, r, d] : hld.path_query_vertex(X, Y)) {
        seg.update(l, r, Z);
      }
    } else {
      int X, Y;
      std::cin >> X >> Y;
      --X, --Y;
      mint ans = 0;
      for (auto [l, r, d] : hld.path_query_vertex(X, Y)) {
        ans += seg.fold(l, r);
      }
      std::cout << ans << "\n";
    }
  }
}
