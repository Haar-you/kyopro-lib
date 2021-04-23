#define PROBLEM "https://yukicoder.me/problems/no/1099"

#include <iostream>
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

using sum = hl::sum_monoid<int64_t>;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N;
  std::cin >> N;

  auto A = hl::input_vector<int64_t>(N);

  hl::lazy_segment_tree<hl::add_square_sum<sum>> seg(N);
  seg.init_with_vector(A);

  int Q;
  std::cin >> Q;

  for (auto [type] : hl::input_tuples<int>(Q)) {
    if (type == 1) {
      int l, r, x;
      std::cin >> l >> r >> x;
      seg.update(l - 1, r, x);
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << seg.fold(l - 1, r).square_sum << "\n";
    }
  }

  return 0;
}
