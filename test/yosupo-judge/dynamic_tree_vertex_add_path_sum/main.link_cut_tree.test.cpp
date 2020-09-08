#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include <iostream>
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/DataStructure/LinkCutTree/link_cut_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  hl::link_cut_tree<hl::sum_monoid<int64_t>> lct(N);

  for(auto [i, a] : hl::input_tuples_with_index<int64_t>(N)){
    lct.update(i, a);
  }

  for(auto [u, v] : hl::input_tuples<int, int>(N - 1)){
    lct.link(u, v);
  }

  for(auto [type] : hl::input_tuples<int>(Q)){
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
