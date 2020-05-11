#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include <iostream>
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/DataStructure/LinkCutTree/link_cut_tree.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  LinkCutTree<SumMonoid<int64_t>> lct(N);

  for(int i = 0; i < N; ++i){
    int64_t a;
    std::cin >> a;
    lct.update(i, a);
  }
  
  for(int i = 0; i < N-1; ++i){
    int u, v; std::cin >> u >> v;
    lct.link(u, v);
  }
  
  while(Q--){
    int type; std::cin >> type;
    
    switch(type){
    case 0: {
      int u, v, w, x; std::cin >> u >> v >> w >> x;

      lct.cut(u, v);
      lct.link(w, x);
      break;
    }
    case 1: {
      int p, x; std::cin >> p >> x;
      lct.update(p, lct.at(p) + x);
      break;
    }
    case 2: {
      int u, v; std::cin >> u >> v;

      auto ans = lct.get(u, v);
      std::cout << ans << std::endl;
      break;
    }
    }
  }

  return 0;
}
