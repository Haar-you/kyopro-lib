#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  SegmentTreeBeats seg(N);

  auto a = input_vector<int64_t>(N);
  seg.init_with_vector(a);
  
  for(auto [type, l, r] : input_tuples<int, int, int>(Q)){
    switch(type){
    case 0: {
      int64_t b; std::cin >> b;
      seg.chmin(l, r, b);
      break;
    }
    case 1: {
      int64_t b; std::cin >> b;
      seg.chmax(l, r, b);
      break;
    }
    case 2: {
      int64_t b; std::cin >> b;
      seg.add(l, r, b);
      break;
    }
    case 3: {
      auto ans = seg.get_sum(l, r);
      std::cout << ans << "\n"; 
      break; 
    }
    }
  }

  return 0;
}
