#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <vector>
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  std::vector<int64_t> x(N), y(N), w(N);

  SegmentTree2D<SumMonoid<int64_t>> seg;

  for(int i = 0; i < N; ++i){
    std::cin >> x[i] >> y[i] >> w[i];
    seg.add(x[i], y[i]);
  }

  seg.build();
  
  for(int i = 0; i < N; ++i){
    seg.update(x[i], y[i], w[i]);
  }
  
  for(int i = 0; i < Q; ++i){
    int64_t l, d, r, u; std::cin >> l >> d >> r >> u;

    auto ans = seg.get(l, d, r, u);
    std::cout << ans << std::endl;
  }

  return 0;
}
