#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  hl::LazySegmentTree<hl::UpdateSum<int64_t, int64_t>> seg(n);

  for(auto [type, s, t] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s, t + 1, x);
    }else{
      std::cout << seg.get(s, t + 1) << std::endl;
    }
  }

  return 0;
}
