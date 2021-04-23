#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955"

#include <iostream>
#include <map>
#include <vector>
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Typical/subset_sum_limited.cpp"

namespace hl = haar_lib;

int main() {
  int N, R;
  std::cin >> N >> R;

  auto p = hl::input_vector<int>(N);
  for (auto &x : p) x -= 1;

  hl::unionfind uf(N);

  for (int i = 0; i < N; ++i) {
    uf.merge(i, p[i]);
  }

  std::map<int, int> cycles;
  for (int i = 0; i < N; ++i) {
    if (i == uf.root_of(i)) cycles[uf.size_of(i)] += 1;
  }

  std::vector<int> a, m;
  for (auto &[k, v] : cycles) {
    a.push_back(k);
    m.push_back(v);
  }

  bool ans = hl::subset_sum_limited(a.size(), R, a, m)[R];

  std::cout << (ans ? "Yes" : "No") << std::endl;

  return 0;
}
