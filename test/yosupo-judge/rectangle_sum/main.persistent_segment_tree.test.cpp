#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <vector>
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Utils/compressor.cpp"
#include "Mylib/Utils/sort_simultaneously.cpp"

namespace hl = haar_lib;

using Seg = hl::persistent_segment_tree<hl::sum_monoid<int64_t>>;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  auto [x, y, w] = hl::input_tuple_vector<int64_t, int64_t, int64_t>(N);

  hl::sort_simultaneously(
      [&](int i, int j) {
        return y[i] < y[j];
      },
      x, y, w);

  auto c      = hl::compressor_builder<int64_t>().add(x).build().compress(x);
  const int m = c.size();

  std::vector<Seg> seg;
  seg.push_back(Seg(m));

  for (int i = 0; i < N; ++i) {
    auto &s = seg.back();
    seg.push_back(s.update(x[i], w[i]));
  }

  for (auto [l, d, r, u] : hl::input_tuples<int64_t, int64_t, int64_t, int64_t>(Q)) {
    l = c.get_index(l);
    r = c.get_index(r);

    u = std::lower_bound(y.begin(), y.end(), u) - y.begin();
    d = std::lower_bound(y.begin(), y.end(), d) - y.begin();

    auto ans = seg[u].fold(l, r) - seg[d].fold(l, r);
    std::cout << ans << "\n";
  }

  return 0;
}
