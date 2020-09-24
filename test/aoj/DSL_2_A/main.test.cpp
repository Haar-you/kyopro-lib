#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <iostream>
#include <climits>
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  hl::segment_tree<hl::min_monoid<int>> seg(n);

  for(auto [type, x, y] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      seg.set(x, y);
    }else{
      std::cout << seg.fold(x, y + 1).value_or(INT_MAX) << std::endl;
    }
  }

  return 0;
}
