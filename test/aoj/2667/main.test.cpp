#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp"
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int N, Q; std::cin >> N >> Q;

  auto tree = convert_to_graph<int, false>(N, input_edges<int, 0, false>(N-1));
  
  auto hld = HLDecomposition(tree, 0);
  LazySegmentTree<AddSum<int64_t,int64_t>> seg(N);
  
  for(auto [c] : input_tuples<int>(Q)){
    if(c == 0){
      int u, v; std::cin >> u >> v;
      
      int64_t ans = 0;
      hld.path_query_edge(
        u,
        v,
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
