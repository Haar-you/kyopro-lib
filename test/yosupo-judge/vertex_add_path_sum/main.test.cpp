#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <iostream>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto a = input_vector<int64_t>(N);

  Tree<int> tree(N);
  tree.read<0, false, false>(N - 1);
  auto hld = HLDecomposition(tree, 0);
  auto seg = SegmentTree<SumMonoid<int64_t>>(N);

  for(int i = 0; i < N; ++i){
    seg.update(hld.get_id(i), a[i]);
  }

  for(auto [t] : input_tuples<int>(Q)){
    if(t == 0){
      int p, x; std::cin >> p >> x;
      
      int i = hld.get_id(p);
      seg.update(i, seg.at(i) + x);
    }else{
      int u, v; std::cin >> u >> v;

      int64_t ans = 0;
      hld.path_query_vertex(
        u,
        v,
        [&](int l, int r){
          ans += seg.get(l, r);
        }
      );

      std::cout << ans << "\n";
    }
  }
  
  return 0;
}
