#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include <iostream>
#include <vector>
#include <utility>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp"
#include "Mylib/AlgebraicStructure/Monoid/affine.cpp"
#include "Mylib/AlgebraicStructure/Monoid/dual.cpp"

using mint = ModInt<998244353>;
using M = DualMonoid<AffineMonoid<mint>>;

int main(){
  int N, Q; scanf("%d%d", &N, &Q);

  Tree<int> tree(N);

  std::vector<std::pair<mint,mint>> f(N);

  for(int i = 0; i < N; ++i){
    int64_t a, b; scanf("%lld%lld", &a, &b);
    f[i] = std::make_pair(a, b);
  }

  for(int i = 0; i < N-1; ++i){
    int u, v; scanf("%d%d", &u, &v);
    add_undirected(tree, u, v, 1);
  }
  
  HLDecomposition<int> hld(tree, 0);

  SegmentTreeBothFoldable<M> seg(N);
  
  for(int i = 0; i < N; ++i){
    seg.update(hld.get_id(i), f[i]);
  }

  while(Q--){
    int type; scanf("%d", &type);

    if(type == 0){
      int64_t p, c, d; scanf("%lld%lld%lld", &p, &c, &d);

      seg.update(hld.get_id(p), std::make_pair(c, d));
    }else{
      int64_t u, v, x; scanf("%lld%lld%lld", &u, &v, &x);

      auto left = M::id(), right = M::id();

      hld.path_query_vertex(
        u,
        v,
        [&](int l, int r){
          left = M::op(left, seg.fold_right(l, r));
        },
        [&](int l, int r){
          right = M::op(seg.fold_left(l, r), right);
        }
      );
      
      auto a = M::op(left, right);

      mint ans = a.first * x + a.second;
      printf("%lld\n", ans.val);
    }
  }

  return 0;
}
