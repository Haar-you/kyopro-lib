#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>

#include "Mylib/DataStructure/SparseTable/sparse_table.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  std::vector<int> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  SparseTable<MinMonoid<int>> s(a);

  while(Q--){
    int l, r; std::cin >> l >> r;

    std::cout << s.get(l, r) << "\n";
  }

  return 0;
}
