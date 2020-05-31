#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int n; std::cin >> n;

  Tree<int> tree(n);
  for(int i = 0; i < n; ++i){
    int k; std::cin >> k;
    for(int j = 0; j < k; ++j){
      int c; std::cin >> c;
      add_edge(tree, i, c, 1);
    }
  }

  auto lca = LCA(tree, 0);

  int q; std::cin >> q;

  for(auto [u, v] : input_tuples<int, int>(q)){
    std::cout << lca.lca(u, v) << std::endl;
  }

  return 0;
}
