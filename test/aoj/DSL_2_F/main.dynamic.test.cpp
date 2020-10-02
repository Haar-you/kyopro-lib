#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <iostream>
#include <climits>
#include "Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/update.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/update_min.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using update = hl::update_monoid<int>;
using min = hl::min_monoid<int>;

int main(){
  int n, q; std::cin >> n >> q;

  hl::dynamic_lazy_segment_tree<hl::update_min<update, min>> seg(n);

  for(auto [type, s, t] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s, t + 1, x);
    }else{
      std::cout << seg.fold(s, t + 1).value_or(INT_MAX) << std::endl;
    }
  }

  return 0;
}
