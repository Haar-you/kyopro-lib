#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int N, Q; std::cin >> N >> Q;

  hl::Tree<int> tree(N);
  tree.read<0, false, false>(N - 1);

  auto hld = hl::HLDecomposition(tree, 0);
  hl::LazySegmentTree<hl::AddSum<int64_t, int64_t>> seg(N);

  for(auto [c] : hl::input_tuples<int>(Q)){
    if(c == 0){
      int u, v; std::cin >> u >> v;

      int64_t ans = 0;
      hld.path_query_edge(
        u, v,
        [&](int l, int r){
          ans += seg.get(l, r);
        }
      );
      std::cout << ans << std::endl;
    }else{
      int v, x; std::cin >> v >> x;

      hld.subtree_query_edge(
        v,
        [&](int l, int r){
          seg.update(l, r, x);
        }
      );
    }
  }

  return 0;
}
