#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp"

int main(){
  int N, Q; std::cin >> N >> Q;
  
  Tree<int> tree(N);
  for(int i = 0; i < N-1; ++i){
    int a, b; std::cin >> a >> b;
    add_undirected(tree, a, b, 1);
  }
  
  auto hld = HLDecomposition(tree, 0);
  LazySegmentTree<AddSum<int64_t,int64_t>> seg(N);
  
  while(Q--){
    int c; std::cin >> c;
    
    if(c == 0){
      int u, v; std::cin >> u >> v;
      
      int64_t ans = 0;
      hld.path_query_edge(u, v, [&](int l, int r){ans += seg.get(l, r);});
      std::cout << ans << std::endl;
    }else{
      int v, x; std::cin >> v >> x;
      
      hld.subtree_query_edge(v, [&](int l, int r){seg.update(l, r, x);});
    }
  }
  
  return 0;
}
