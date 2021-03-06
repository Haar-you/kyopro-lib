#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <iostream>
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using sum = hl::sum_monoid<int64_t>;

int main() {
  int n, q;
  std::cin >> n >> q;

  hl::lazy_segment_tree<hl::add_sum<sum, sum>> seg(n);

  for (auto [type, s, t] : hl::input_tuples<int, int, int>(q)) {
    if (type == 0) {
      int x;
      std::cin >> x;
      seg.update(s - 1, t, x);
    } else {
      std::cout << seg.fold(s - 1, t) << std::endl;
    }
  }

  return 0;
}
