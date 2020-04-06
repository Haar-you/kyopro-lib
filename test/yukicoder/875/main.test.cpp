#define PROBLEM "https://yukicoder.me/problems/no/875"

#include <iostream>
#include <vector>
#include <utility>

#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/with_index.cpp"

using Mon = WithIndex<MinMonoid<int>, MinMonoid<int>>;

int main(){
  int N, Q; scanf("%d %d", &N, &Q);

  SegmentTree<Mon> seg(N);

  std::vector<Mon::value_type> a(N);
  for(int i = 0; i < N; ++i){
    int x; scanf("%d", &x);
    a[i] = std::make_pair(x, i);
  }

  seg.init_with_vector(a);

  for(int i = 0; i < Q; ++i){
    int type; scanf("%d", &type);
    
    switch(type){
    case 1: {
      int l, r; scanf("%d %d", &l, &r);
      --l, --r;

      auto x = seg[l].first;
      auto y = seg[r].first;

      seg.update(l, std::make_pair(y, l));
      seg.update(r, std::make_pair(x, r));

      break;
    }
    case 2: {
      int l, r; scanf("%d %d", &l, &r);
      --l, --r;

      printf("%d\n", seg.get(l, r+1).second + 1);

      break;
    }
    }
  }

  return 0;
}
