#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <iostream>
#include <climits>
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  SegmentTree<MinMonoid<int>> seg(n);

  for(auto [type, x, y] : input_tuples<int, int, int>(q)){
    if(type == 0){
      seg.update(x, y);
    }else{
      std::cout << seg.get(x, y + 1).value_or(INT_MAX) << std::endl;
    }
  }

  return 0;
}
