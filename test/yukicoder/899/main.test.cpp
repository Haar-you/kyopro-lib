#define PROBLEM "https://yukicoder.me/problems/no/899"

#include <iostream>

#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;

  auto tree = convert_to_graph<int, false>(N, input_edges<int, 0, false>(N-1));

  auto res = EulerTourBFS<int>(tree, 0);

  std::vector<int64_t> A(N);
  for(int i = 0; i < N; ++i) std::cin >> A[i];
  LazySegmentTree<UpdateSum<int64_t, int64_t>> seg(N);
  
  for(int i = 0; i < N; ++i){
    res.query_at(i, [&](int l, int r){seg.update(l, r, A[i]);});
  }
    
  int Q; std::cin >> Q;
  while(Q--){
    int x; std::cin >> x;

    int64_t ans = 0;

    auto f =
      [&](int l, int r){
        ans += seg.get(l, r);
        seg.update(l, r, 0);
      };

    // 親の親
    res.query_at(res.get_ancestor(x, 2), f);

    // 親
    res.query_at(res.get_ancestor(x, 1), f);
    
    // 親の子
    res.query_children(res.get_parent(x), 1, f);

    // 自分
    res.query_at(x, f);
    
    // 子
    res.query_children(x, 1, f);

    // 子の子
    res.query_children(x, 2, f);
    
    res.query_at(
      x,
      [&](int l, int r){
        seg.update(l, r, ans);
      }
    );
    
    std::cout << ans << std::endl;
  }

  return 0;
}
