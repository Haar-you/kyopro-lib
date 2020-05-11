#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"

int main(){
  int N, Q; scanf("%d %d", &N, &Q);

  std::vector<int64_t> a(N);
  for(int i = 0; i < N; ++i) scanf("%lld", &a[i]);

  Tree<int> tree(N);
  for(int i = 1; i < N; ++i){
    int p; scanf("%d", &p);
    add_edge(tree, p, i, 1);
  }

  auto seg = SegmentTree<SumMonoid<int64_t>>(N);
  auto hld = HLDecomposition(tree, 0);

  for(int i = 0; i < N; ++i){
    seg.update(hld.get_id(i), a[i]);
  }

  while(Q--){
    int t; scanf("%d", &t);

    if(t == 0){
      int u, x; scanf("%d %d", &u, &x);

      int i = hld.get_id(u);
      seg.update(i, seg.at(i) + x);
    }else{
      int u; scanf("%d", &u);

      int64_t ans = 0;
      hld.subtree_query_vertex(u, [&](int l, int r){ans += seg.get(l, r);});

      printf("%lld\n", ans);
    }
  }
  
  return 0;
}
