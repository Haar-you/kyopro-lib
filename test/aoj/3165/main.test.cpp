#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  auto seg = hl::segment_tree_linear_add<int64_t>(N);

  for (auto [l, k] : hl::input_tuples<int, int>(Q)) {
    --l;
    seg.update(l, l + k, 1, 1);
  }

  auto ans = seg.get_all(N);
  std::cout << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}
