#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  auto seg = SegmentTree<SumMonoid<int>>(n);

  for(int i = 0; i < q; ++i){
    int type; std::cin >> type;

    if(type == 0){
      int x,y; std::cin >> x >> y;
      seg.update(x-1, seg[x-1] + y);
    }else{
      int x,y; std::cin >> x >> y;
      std::cout << seg.get(x-1, y) << std::endl;
    }
  }
  
  return 0;
}
