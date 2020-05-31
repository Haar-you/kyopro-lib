#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3132"
#define ERROR 1e-7

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Mylib/AlgebraicStructure/Monoid/product.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int N; std::cin >> N;
  
  auto seg = SegmentTree<ProductMonoid<double>>(N);

  auto [T, A] = input_tuple_vector<int, int>(N);
  
  for(int i = 0; i < N; ++i){
    seg.update(i, 0.1 * (10 - A[i]));
  }

  int Q; std::cin >> Q;

  for(auto [L, R] : input_tuples<int, int>(Q)){
    int l = std::lower_bound(T.begin(), T.end(), L) - T.begin();
    int r = std::lower_bound(T.begin(), T.end(), R) - T.begin();
    
    auto ans = seg.get(l, r) * 1e9;
    
    std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  }

  return 0;
}
