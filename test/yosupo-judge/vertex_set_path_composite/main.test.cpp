#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include <iostream>
#include <vector>
#include <utility>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp"
#include "Mylib/AlgebraicStructure/Monoid/affine.cpp"
#include "Mylib/AlgebraicStructure/Monoid/dual.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;
using Monoid = hl::dual_monoid<hl::affine_monoid<mint>>;
const Monoid M;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto f = hl::input_vector<std::pair<mint, mint>>(N);
  hl::tree<int> tree(N);
  tree.read<0, false, false>(N - 1);

  hl::hl_decomposition<int> hld(tree, 0);
  hl::segment_tree_both_foldable<Monoid> seg(N);

  for(int i = 0; i < N; ++i){
    seg.update(hld.get_id(i), f[i]);
  }

  for(auto [type] : hl::input_tuples<int>(Q)){
    if(type == 0){
      int64_t p, c, d; std::cin >> p >> c >> d;

      seg.update(hld.get_id(p), std::make_pair(c, d));
    }else{
      int64_t u, v, x; std::cin >> u >> v >> x;

      auto res = M();
      for(auto [l, r, d] : hld.path_query_vertex(u, v)){
        if(d) res = M(res, seg.fold_left(l, r));
        else res = M(res, seg.fold_right(l, r));
      }

      mint ans = res.first * x + res.second;
      std::cout << ans << "\n";
    }
  }

  return 0;
}
