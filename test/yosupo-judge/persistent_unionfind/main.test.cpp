#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/UnionFind/persistent_unionfind.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  std::vector<hl::persistent_unionfind> G(Q + 1);

  G[0] = hl::persistent_unionfind(N);

  for (auto [i, t, k, u, v] : hl::input_tuples_with_index<int, int, int, int>(Q)) {
    ++k;
    ++i;

    if (t == 0) {
      G[i] = G[k].merge(u, v);
    } else {
      std::cout << G[k].is_same(u, v) << "\n";
    }
  }

  return 0;
}
