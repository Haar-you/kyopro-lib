#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_min.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  LazySegmentTree<AddMin<int64_t, int64_t>> seg(n);
  seg.init(0);

  for(auto [type, s, t] : input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s, t + 1, x);
    }else{
      std::cout << seg.get(s, t + 1).value() << std::endl;
    }
  }

  return 0;
}
