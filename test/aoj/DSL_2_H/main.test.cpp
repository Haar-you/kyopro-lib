#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_min.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  hl::lazy_segment_tree<hl::min_monoid<int64_t>, hl::sum_monoid<int64_t>, hl::add_min> seg(n);
  seg.init(0);

  for(auto [type, s, t] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s, t + 1, x);
    }else{
      std::cout << seg.fold(s, t + 1).value() << std::endl;
    }
  }

  return 0;
}
