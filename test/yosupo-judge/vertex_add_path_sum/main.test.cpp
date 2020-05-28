#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <iostream>
#include <vector>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  std::vector<int64_t> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  auto tree = convert_to_graph<int, false>(N, input_edges<int, 0, false>(N-1));

  auto hld = HLDecomposition(tree, 0);
  auto seg = SegmentTree<SumMonoid<int64_t>>(N);

  for(int i = 0; i < N; ++i){
    seg.update(hld.get_id(i), a[i]);
  }

  while(Q--){
    int t; std::cin >> t;
    
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
