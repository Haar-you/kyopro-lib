#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  LazySegmentTree<AddSum<int64_t,int64_t>> seg(n);

  for(auto [type, s, t] : input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s-1, t, x);
    }else{
      std::cout << seg.get(s-1, t) << std::endl;
    }
  }
  
  return 0;
}

