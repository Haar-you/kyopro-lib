#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/tree_height.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int n; std::cin >> n;

  auto tree = convert_to_graph<int, false>(n, input_edges<int, 0, true>(n-1));

  auto ans = tree_height(tree);
  
  for(auto x : ans) std::cout << x << std::endl;

  return 0;
}
