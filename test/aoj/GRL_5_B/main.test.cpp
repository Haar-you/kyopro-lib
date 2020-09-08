#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/tree_height.cpp"

namespace hl = haar_lib;

int main(){
  int n; std::cin >> n;

  hl::Tree<int> tree(n);
  tree.read<0, false>(n - 1);

  auto ans = hl::tree_height(tree);

  for(auto x : ans) std::cout << x << std::endl;

  return 0;
}
