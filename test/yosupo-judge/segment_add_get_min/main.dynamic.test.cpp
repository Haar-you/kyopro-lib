#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <iostream>
#include <climits>
#include "Mylib/DataStructure/ConvexHullTrick/dynamic_lichao_segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto lc = DynamicLiChaoSegmentTree<int64_t, std::less<>>(INT_MIN, INT_MAX);

  for(auto [l, r, a, b] : input_tuples<int64_t, int64_t, int64_t, int64_t>(N)){
    lc.add_segment(l, r, a, b);
  }

  for(auto [type] : input_tuples<int>(Q)){
    if(type == 0){
      int64_t l, r, a, b; std::cin >> l >> r >> a >> b;
      lc.add_segment(l, r, a, b);
    }else{
      int64_t p; std::cin >> p;
      auto ans = lc(p);
      if(ans) std::cout << *ans << "\n";
      else std::cout << "INFINITY" << "\n";
    }
  }

  return 0;
}
