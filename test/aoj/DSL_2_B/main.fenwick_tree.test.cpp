#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "Mylib/AlgebraicStructure/Group/sum.cpp"
#include "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main() {
  int n, q;
  std::cin >> n >> q;

  auto fen = hl::fenwick_tree<hl::sum_group<int>>(n);

  for (auto [type, x, y] : hl::input_tuples<int, int, int>(q)) {
    if (type == 0) {
      fen.update(x - 1, y);
    } else {
      std::cout << fen.fold(x - 1, y) << std::endl;
    }
  }

  return 0;
}
