#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/SparseTable/sparse_table.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto a = input_vector<int>(N);

  SparseTable<MinMonoid<int>> s(a);

  for(auto [l, r] : input_tuples<int, int>(Q)){
    std::cout << s.get(l, r).value() << "\n";
  }

  return 0;
}
