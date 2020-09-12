#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/SparseTable/sparse_table.cpp"
#include "Mylib/AlgebraicStructure/Monoid/bounded_min.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto a = hl::input_vector<int>(N);

  hl::sparse_table<hl::bounded_min_monoid<int>> s(a);

  for(auto [l, r] : hl::input_tuples<int, int>(Q)){
    std::cout << s.get(l, r).value() << "\n";
  }

  return 0;
}
