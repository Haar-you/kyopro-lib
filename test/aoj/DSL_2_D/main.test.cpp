#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include <iostream>
#include <climits>
#include "Mylib/DataStructure/SegmentTree/Static/Dual/dual_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/update_monoid.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  auto seg = DualSegmentTree<UpdateMonoid<int>>(n);
  seg.init(INT_MAX);

  while(q--){
    int type; std::cin >> type;

    if(type == 0){
      int s,t,x; std::cin >> s >> t >> x;
      seg.update(s, t+1, x);
    }else{
      int i; std::cin >> i;
      std::cout << *seg.get(i) << std::endl;
    }
  }

  return 0;
}
