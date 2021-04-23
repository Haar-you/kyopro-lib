#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444"

#include <array>
#include <iostream>
#include <set>
#include <string>
#include "Mylib/AlgebraicStructure/Monoid/pair.cpp"
#include "Mylib/AlgebraicStructure/Monoid/rolling_hash.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main() {
  using Monoid1 = hl::rolling_hash_monoid<1000000007, 33>;
  using Monoid2 = hl::rolling_hash_monoid<1000000007, 100>;

  int n, m;
  std::cin >> n >> m;
  std::string s;
  std::cin >> s;

  hl::segment_tree<hl::pair_monoid<Monoid1, Monoid2>> seg(n);
  for (int i = 0; i < n; ++i) {
    seg.set(i, {Monoid1::value_type(s[i]), Monoid2::value_type(s[i])});
  }

  std::set<std::pair<int64_t, int64_t>> set;
  int l = 0, r = 1;

  for (int i = 0; i < m; ++i) {
    std::string q;
    std::cin >> q;

    if (q[0] == 'L') {
      if (q[1] == '+')
        ++l;
      else
        --l;
    } else {
      if (q[1] == '+')
        ++r;
      else
        --r;
    }

    auto t = seg.fold(l, r);
    set.emplace(t.first.hash, t.second.hash);
  }

  std::cout << set.size() << "\n";

  return 0;
}
