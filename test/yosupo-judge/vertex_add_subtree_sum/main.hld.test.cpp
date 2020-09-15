#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto a = hl::input_vector<int64_t>(N);

  hl::tree<int> tree(N);
  for(int i = 1; i < N; ++i){
    int p; std::cin >> p;
    tree.add_edge(p, i, 1);
  }

  auto seg = hl::segment_tree<hl::sum_monoid<int64_t>>(N);
  auto hld = hl::hl_decomposition(tree, 0);

  for(int i = 0; i < N; ++i){
    seg.update(hld.get_id(i), a[i]);
  }

  for(auto [t, u] : hl::input_tuples<int, int>(Q)){
    if(t == 0){
      int x; std::cin >> x;

      int i = hld.get_id(u);
      seg.update(i, seg[i] + x);
    }else{
      int64_t ans = 0;
      auto [l, r] = hld.subtree_query_vertex(u);
      ans += seg.get(l, r);

      std::cout << ans << "\n";
    }
  }

  return 0;
}
