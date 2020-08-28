#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <iostream>
#include <tuple>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/tree_diameter.cpp"

int main(){
  int n; std::cin >> n;

  Tree<int> tree(n);
  tree.read<0, false>(n - 1);

  int ans = tree_diameter(tree).first;
  std::cout << ans << std::endl;

  return 0;
}
