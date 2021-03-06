#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include <iostream>
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/DataStructure/BBST/splay_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

namespace hl = haar_lib;

int main() {
  int n, q;
  std::cin >> n >> q;

  hl::splay_tree<hl::min_monoid<int>> s(n);

  for (auto [i, a] : hl::input_tuples_with_index<int>(n)) {
    s.set(i, {a});
  }

  for (auto [x, y, z] : hl::input_tuples<int, int, int>(q)) {
    if (x == 0) {
      auto temp = s.get(z).value();
      s.erase(z);
      s.insert(y, {temp});
    } else if (x == 1) {
      auto ans = s.fold(y, z + 1).value();
      std::cout << ans << std::endl;
    } else {
      s.set(y, z);
    }
  }

  return 0;
}
