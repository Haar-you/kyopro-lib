#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include <functional>
#include <iostream>
#include "Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main() {
  int n, q;
  std::cin >> n >> q;

  hl::starry_sky_tree<int, std::less<>> seg(n);

  for (auto [type, s, t] : hl::input_tuples<int, int, int>(q)) {
    if (type == 0) {
      int x;
      std::cin >> x;
      seg.update(s, t + 1, x);
    } else {
      std::cout << seg.fold(s, t + 1) << std::endl;
    }
  }

  return 0;
}
