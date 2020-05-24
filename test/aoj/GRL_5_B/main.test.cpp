#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/tree_height.cpp"

int main(){
  int n; std::cin >> n;

  Tree<int> tree(n);
  for(int i = 0; i < n-1; ++i){
    int s, t, d; std::cin >> s >> t >> d;
    add_undirected(tree, s, t, d);
  }

  auto ans = tree_height(tree);
  
  for(auto x : ans) std::cout << x << std::endl;

  return 0;
}
