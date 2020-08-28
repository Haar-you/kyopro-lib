#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>
#include "Mylib/Graph/TreeUtils/euler_tour_vertex.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto a = input_vector<int64_t>(N);

  Tree<int> tree(N);
  for(int i = 1; i < N; ++i){
    int p; std::cin >> p;
    tree.add_edge(p, i, 1);
  }

  auto seg = SegmentTree<SumMonoid<int64_t>>(N);
  auto et = EulerTourVertex(tree, 0);

  for(int i = 0; i < N; ++i){
    et.point_query(
      i,
      [&](int j){
        seg.update(j, a[i]);
      }
    );
  }

  for(auto [t, u] : input_tuples<int, int>(Q)){
    if(t == 0){
      int x; std::cin >> x;

      et.point_query(
        u,
        [&](int j){
          seg.update(j, seg.at(j) + x);
        }
      );
    }else{
      int64_t ans = 0;
      et.subtree_query(
        u,
        [&](int l, int r){
          ans += seg.get(l, r);
        }
      );

      std::cout << ans << "\n";
    }
  }
  
  return 0;
}
