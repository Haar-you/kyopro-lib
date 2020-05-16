#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  SegmentTreeBeats seg(N);

  std::vector<int64_t> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  seg.init_with_vector(a);
  
  while(Q--){
    int type; std::cin >> type;
    
    switch(type){
    case 0: {
      int64_t l, r, b; std::cin >> l >> r >> b;
      seg.chmin(l, r, b);
      break;
    }
    case 1: {
      int64_t l, r, b; std::cin >> l >> r >> b;
      seg.chmax(l, r, b);
      break;
    }
    case 2: {
      int64_t l, r, b; std::cin >> l >> r >> b;
      seg.add(l, r, b);
      break;
    }
    case 3: {
      int l, r; std::cin >> l >> r;

      auto ans = seg.get_sum(l, r);
      std::cout << ans << "\n"; 
      break; 
    }
    }
  }

  return 0;
}
