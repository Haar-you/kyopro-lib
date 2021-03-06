#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <vector>
#include "Mylib/AlgebraicStructure/Monoid/affine.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Number/Mint/mint.cpp"

namespace hl = haar_lib;

using mint   = hl::modint<998244353>;
using sum    = hl::sum_monoid<mint>;
using affine = hl::affine_monoid<mint>;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  auto seg = hl::lazy_segment_tree<hl::affine_sum<affine, sum>>(N);
  auto a   = hl::input_vector<mint>(N);
  seg.init_with_vector(a);

  for (auto [t, l, r] : hl::input_tuples<int, int, int>(Q)) {
    if (t == 0) {
      int b, c;
      std::cin >> b >> c;
      seg.update(l, r, std::make_pair(b, c));
    } else {
      std::cout << seg.fold(l, r) << "\n";
    }
  }

  return 0;
}
