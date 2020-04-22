#define PROBLEM "https://yukicoder.me/problems/no/1030"

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/max_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/maybe_monoid.cpp"

struct LCASemigroup{
  using value_type = int;
  static std::function<int(int,int)> op;
};

std::function<int(int,int)> LCASemigroup::op;


int main(){
  int N, K, Q; std::cin >> N >> K >> Q;
  std::vector<int> C(N);
  for(auto &x : C) std::cin >> x;
  
  std::vector<int> A(K);
  for(auto &x : A){
    std::cin >> x;
    --x;
  }

  Tree<int> tree(N);
  for(int i = 0; i < N-1; ++i){
    int e, f; std::cin >> e >> f;
    --e, --f;
    add_edge(tree, f, e, 1);
  }

  HLDecomposition<int> hld(tree, 0);
  LCASemigroup::op = [&](int a, int b) -> int{return hld.lca(a, b);};

  SegmentTree<MaxMonoid<int>> seg1(N);
  for(int i = 0; i < N; ++i){
    seg1.update(hld.get_id(i), C[i]);
  }

  SegmentTree<MaybeMonoid<LCASemigroup>> seg2(K);
  seg2.init_with_vector(A);

  while(Q--){
    int T; std::cin >> T;

    if(T == 1){
      int X, Y; std::cin >> X >> Y;
      --X; --Y;

      seg2.update(X, Y);
    }else{
      int L, R; std::cin >> L >> R;
      
      int lca = *seg2.get(L-1, R);
      int ans = 0;
      hld.path_query_vertex(0, lca,
                            [&](int l, int r){
                              ans = std::max(ans, seg1.get(l, r));
                            });
      
      std::cout << ans << "\n";
    }
  }

  return 0;
}
