#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0390"

#include <iostream>
#include <variant>
#include "Mylib/AlgebraicStructure/Group/dihedral.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

static int K;
using M = hl::dihedral_group<K>;

int main() {
  int N, Q;
  std::cin >> K >> N >> Q;
  auto A = hl::input_vector<int>(N);

  hl::segment_tree<M> seg(N);

  for (int i = 0; i < N; ++i) {
    if (A[i] > 0) {
      seg.set(i, M::R({A[i] % K}));
    } else if (A[i] < 0) {
      seg.set(i, M::R({A[i] % K + K}));
    } else {
      seg.set(i, M::S({0}));
    }
  }

  for (auto [L, R] : hl::input_tuples<int, int>(Q)) {
    --L, --R;

    auto x = seg[L];
    auto y = seg[R];
    seg.set(L, y);
    seg.set(R, x);

    auto res = seg.fold_all();

    if (std::holds_alternative<M::R>(res)) {
      int ans = (K - std::get<M::R>(res).value) % K + 1;
      std::cout << ans << "\n";
    } else {
      int ans = -(std::get<M::S>(res).value + 1);
      std::cout << ans << "\n";
    }
  }

  return 0;
}
