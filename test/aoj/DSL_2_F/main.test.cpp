#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <iostream>
#include <climits>
#include "Mylib/DataStructure/SegmentTree/Static/Lazy/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/update_min.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  LazySegmentTree<UpdateMin<int,int>> seg(n);
  seg.init(INT_MAX);

  while(q--){
    int type; std::cin >> type;

    if(type == 0){
      int s,t,x; std::cin >> s >> t >> x;

      seg.update(s, t+1, x);
    }else{
      int s,t; std::cin >> s >> t;

      std::cout << seg.get(s, t+1) << std::endl;
    }
  }
  
  return 0;
}
