#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  auto seg = DualSegmentTree<SumMonoid<int>>(n);

  for(auto [type] : input_tuples<int>(q)){
    if(type == 0){
      int s, t, x; std::cin >> s >> t >> x;
      seg.update(s - 1, t, x);
    }else{
      int t; std::cin >> t;
      std::cout << seg[t - 1] << std::endl;
    }
  }

  return 0;
}
