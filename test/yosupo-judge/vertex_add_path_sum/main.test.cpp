#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <iostream>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto a = hl::input_vector<int64_t>(N);

  hl::tree<int> tree(N);
  tree.read<0, false, false>(N - 1);
  auto hld = hl::hl_decomposition(tree, 0);
  auto seg = hl::segment_tree<hl::sum_monoid<int64_t>>(N);

  for(int i = 0; i < N; ++i){
    seg.set(hld.get_id(i), a[i]);
  }

  for(auto [t] : hl::input_tuples<int>(Q)){
    if(t == 0){
      int p, x; std::cin >> p >> x;

      int i = hld.get_id(p);
      seg.update(i, x);
    }else{
      int u, v; std::cin >> u >> v;

      int64_t ans = 0;
      for(auto [l, r, d] : hld.path_query_vertex(u, v)){
        ans += seg.fold(l, r);
      }

      std::cout << ans << "\n";
    }
  }

  return 0;
}
