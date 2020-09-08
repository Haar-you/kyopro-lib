#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  auto seg = hl::segment_tree<hl::sum_monoid<int>>(n);

  for(auto [type, x, y] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      seg.update(x - 1, seg[x - 1] + y);
    }else{
      std::cout << seg.get(x - 1, y) << std::endl;
    }
  }

  return 0;
}
