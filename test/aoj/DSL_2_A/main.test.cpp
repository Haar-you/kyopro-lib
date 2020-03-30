#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min_monoid.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  SegmentTree<MinMonoid<int>> seg(n);
  
  while(q--){
    int type; std::cin >> type;

    if(type == 0){
      int x, y; std::cin >> x >> y;
      seg.update(x, y);
    }else{
      int x, y; std::cin >> x >> y;
      std::cout << seg.get(x, y + 1) << std::endl;
    }
  }

  return 0;
}
