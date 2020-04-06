#define PROBLEM "https://yukicoder.me/problems/no/789"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/Dynamic/dynamic_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp"

int main(){
  int n; scanf("%d", &n);

  DynamicSegmentTree<SumMonoid<int64_t>> seg(1000000001);

  int64_t ans = 0;
    
  for(int i = 0; i < n; ++i){
    int q,x,y; scanf("%d%d%d", &q, &x, &y);
    if(q == 0){
      seg.update(x, seg[x] + y);
    }else{
      ans += seg.get(x, y+1);
    }
  }

  printf("%lld\n", ans);
  
  return 0;
}
