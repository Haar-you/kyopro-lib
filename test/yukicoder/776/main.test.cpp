#define PROBLEM "https://yukicoder.me/problems/no/776"

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include "Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

using M = hl::max_partial_sum_monoid<int64_t>;

int main() {
  int N, Q;
  std::cin >> N >> Q;

  hl::segment_tree<M> seg(N);

  auto a = hl::input_vector<int64_t>(N);
  for (int i = 0; i < N; ++i) {
    seg.set(i, M::max_partial_sum(a[i]));
  }

  for (auto [type] : hl::input_tuples<std::string>(Q)) {
    if (type == "set") {
      int i, x;
      std::cin >> i >> x;
      --i;
      seg.set(i, M::max_partial_sum(x));
      a[i] = x;
    } else {
      int l1, l2, r1, r2;
      std::cin >> l1 >> l2 >> r1 >> r2;
      --l1, --l2, --r1, --r2;

      r1 = std::max(l1, r1);
      l2 = std::min(l2, r2);

      int64_t ans = LLONG_MIN;

      auto f =
          [&](int L1, int L2, int R1, int R2) {
            auto ret =
                seg.fold(L1, L2 + 1).value_or(M::max_partial_sum(0)).right_max +
                seg.fold(std::min(L2 + 1, R1), R1).value_or(M::max_partial_sum(0)).sum +
                seg.fold(R1, R2 + 1).value_or(M::max_partial_sum(0)).left_max;

            if (L2 == R1) ret -= a[L2];

            return ret;
          };

      if (l2 <= r1) {
        ans = f(l1, l2, r1, r2);
      } else {
        if (l1 <= r1) ans = std::max(ans, f(l1, r1, r1, r2));
        if (l2 <= r2) ans = std::max(ans, f(l1, l2, l2, r2));
        if (r1 <= l2) ans = std::max(ans, seg.fold(r1, l2 + 1)->partial_max);
      }

      std::cout << ans << "\n";
    }
  }

  return 0;
}
