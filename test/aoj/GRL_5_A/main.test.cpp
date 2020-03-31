#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <iostream>
#include <tuple>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/tree_utils.cpp"

int main(){
  int n; std::cin >> n;
  Tree<int> tree(n);

  for(int i = 0; i < n-1; ++i){
    int s, t, w; std::cin >> s >> t >> w;
    add_undirected(tree, s, t, w);
  }

  int ans;
  std::tie(std::ignore, std::ignore, ans) = TreeUtils<int>::diameter(tree);
  std::cout << ans << std::endl;

  return 0;
}
