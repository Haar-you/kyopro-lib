#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include <iostream>
#include <queue>
#include <tuple>
#include "Mylib/AlgebraicStructure/Group/sum.cpp"
#include "Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H, W, T, Q;
  std::cin >> H >> W >> T >> Q;

  hl::fenwick_tree_2d<hl::sum_group<int>> seg1(H, W), seg2(H, W);

  std::queue<std::tuple<int, int, int>> q;

  for (auto [t, c] : hl::input_tuples<int, int>(Q)) {
    while (q.size()) {
      auto &a = q.front();

      if (t >= std::get<2>(a) + T) {
        int x = std::get<0>(a), y = std::get<1>(a);

        seg1.update({x, y}, 1);
        seg2.update({x, y}, -1);

        q.pop();
      } else {
        break;
      }
    }

    if (c == 0) {
      int h, w;
      std::cin >> h >> w;
      --h, --w;

      seg2.update({h, w}, 1);
      q.emplace(h, w, t);
    } else if (c == 1) {
      int h, w;
      std::cin >> h >> w;
      --h, --w;

      if (seg1[{h, w}] == 1) seg1.update({h, w}, -1);
    } else {
      int h1, w1, h2, w2;
      std::cin >> h1 >> w1 >> h2 >> w2;
      --h1, --w1;

      std::cout << seg1.fold({h1, w1}, {h2, w2}) << " " << seg2.fold({h1, w1}, {h2, w2}) << std::endl;
    }
  }

  return 0;
}
