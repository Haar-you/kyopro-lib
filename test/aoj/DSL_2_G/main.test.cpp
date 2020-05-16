#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  LazySegmentTree<AddSum<int64_t,int64_t>> seg(n);

  while(q--){
    int type; std::cin >> type;

    if(type == 0){
      int s,t,x; std::cin >> s >> t >> x;

      seg.update(s-1, t, x);
    }else{
      int s,t; std::cin >> s >> t;

      std::cout << seg.get(s-1, t) << std::endl;
    }
  }
  
  return 0;
}

