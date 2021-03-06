#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include <climits>
#include <iostream>
#include "Mylib/AlgebraicStructure/Monoid/update.cpp"
#include "Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main() {
  int n, q;
  std::cin >> n >> q;

  auto seg = hl::dual_segment_tree<hl::update_monoid<int>>(n);
  seg.init(INT_MAX);

  for (auto [type] : hl::input_tuples<int>(q)) {
    if (type == 0) {
      int s, t, x;
      std::cin >> s >> t >> x;
      seg.update(s, t + 1, x);
    } else {
      int i;
      std::cin >> i;
      std::cout << *seg[i] << std::endl;
    }
  }

  return 0;
}
