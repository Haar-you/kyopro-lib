#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <vector>
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto [x, y, w] = input_tuple_vector<int64_t, int64_t, int64_t>(N);

  SegmentTree2D<SumMonoid<int64_t>> seg;

  for(int i = 0; i < N; ++i){
    seg.add(x[i], y[i]);
  }

  seg.build();

  for(int i = 0; i < N; ++i){
    seg.update({x[i], y[i]}, w[i]);
  }

  for(auto [l, d, r, u] : input_tuples<int64_t, int64_t, int64_t, int64_t>(Q)){
    auto ans = seg.get({l, d}, {r, u});
    std::cout << ans << std::endl;
  }

  return 0;
}
