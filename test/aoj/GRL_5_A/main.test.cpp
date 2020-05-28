#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <iostream>
#include <tuple>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/tree_diameter.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int n; std::cin >> n;

  auto tree = convert_to_graph<int, false>(n, input_edges<int, 0, true>(n-1));

  int ans;
  std::tie(ans, std::ignore) = tree_diameter(tree);
  std::cout << ans << std::endl;

  return 0;
}
