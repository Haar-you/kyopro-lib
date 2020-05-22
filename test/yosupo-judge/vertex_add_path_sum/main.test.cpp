#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <iostream>
#include <vector>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"

int main(){
  int N, Q; scanf("%d %d", &N, &Q);

  std::vector<int64_t> a(N);
  for(int i = 0; i < N; ++i) scanf("%lld", &a[i]);

  Tree<int> tree(N);
  for(int i = 0; i < N-1; ++i){
    int u, v; scanf("%d %d", &u, &v);
    add_undirected(tree, u, v, 1);
  }

  auto hld = HLDecomposition(tree, 0);
  auto seg = SegmentTree<SumMonoid<int64_t>>(N);

  for(int i = 0; i < N; ++i){
    seg.update(hld.get_id(i), a[i]);
  }

  while(Q--){
    int t; scanf("%d", &t);
    
    if(t == 0){
      int p, x; scanf("%d %d", &p, &x);
      
      int i = hld.get_id(p);
      seg.update(i, seg.at(i) + x);
    }else{
      int u, v; scanf("%d %d", &u, &v);

      int64_t ans = 0;
      hld.path_query_vertex(
        u,
        v,
        [&](int l, int r){
          ans += seg.get(l, r);
        }
      );

      printf("%lld\n", ans);
    }
  }
  
  return 0;
}
