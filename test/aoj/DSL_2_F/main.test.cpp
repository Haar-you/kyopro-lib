#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <iostream>
#include <climits>
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/update_min.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  LazySegmentTree<UpdateMin<int,int>> seg(n);
  seg.init(INT_MAX);

  for(auto [type, s, t] : input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s, t+1, x);
    }else{
      std::cout << seg.get(s, t+1) << std::endl;
    }
  }
  
  return 0;
}
