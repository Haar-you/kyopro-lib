#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include "Mylib/DataStructure/RangeTree/range_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

namespace hl = haar_lib;

int main() {
  int n;
  std::cin >> n;
  hl::range_tree_builder builder;

  std::map<std::pair<int, int>, int> m;

  for (auto [i, x, y] : hl::input_tuples_with_index<int, int>(n)) {
    builder.add(x, y);
    m[{x, y}] = i;
  }

  auto rt = builder.build();

  int q;
  std::cin >> q;

  for (auto [sx, tx, sy, ty] : hl::input_tuples<int, int, int, int>(q)) {
    auto res = rt.get({sx, sy}, {tx + 1, ty + 1});

    std::vector<int> ans;
    for (auto &p : res) ans.push_back(m[p]);

    std::sort(ans.begin(), ans.end());
    for (auto &x : ans) {
      std::cout << x << "\n";
    }
    std::cout << "\n";
  }

  return 0;
}
