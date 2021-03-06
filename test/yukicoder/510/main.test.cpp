#define PROBLEM "https://yukicoder.me/problems/no/510"

#include <iostream>
#include <vector>
#include "Mylib/AlgebraicStructure/Monoid/dual.cpp"
#include "Mylib/AlgebraicStructure/Monoid/product_matrix.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/LinearAlgebra/square_matrix_const_size.cpp"
#include "Mylib/Number/Mint/mint.cpp"

namespace hl = haar_lib;

using mint   = hl::modint<1000000007>;
using Mat    = hl::square_matrix_const<mint, 4>;
using Monoid = hl::dual_monoid<hl::product_matrix_monoid<Mat>>;

auto f(mint x, mint y) {
  Mat ret = {
      {1, 0, x, 0},
      {0, y, 0, 1},
      {0, 2 * y, y * y, 1},
      {0, 0, 0, 1}};
  return ret;
}

int main() {
  int n, q;
  std::cin >> n >> q;

  hl::segment_tree<Monoid> seg(n);
  std::vector<mint> x(n), y(n);

  for (int i = 0; i < n; ++i) {
    seg.set(i, f(x[i], y[i]));
  }

  for (auto [c, i] : hl::input_tuples<char, int>(q)) {
    if (c == 'x') {
      int v;
      std::cin >> v;
      x[i] = v;

      seg.set(i, f(x[i], y[i]));
    } else if (c == 'y') {
      int v;
      std::cin >> v;
      y[i] = v;

      seg.set(i, f(x[i], y[i]));
    } else {
      auto m   = seg.fold(0, i);
      auto ans = dot(m[0], Mat::vector_type({1, 1, 1, 1}));
      std::cout << ans << "\n";
    }
  }

  return 0;
}
