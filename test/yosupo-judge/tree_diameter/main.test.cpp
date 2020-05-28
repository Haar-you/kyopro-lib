#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/tree_diameter.cpp"
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;

  auto tree = convert_to_graph<int64_t, false>(N, input_edges<int64_t, 0, true>(N-1));

  auto [cost, path] = tree_diameter(tree);

  std::cout
    << cost << " " << path.size() << "\n"
    << join(path.begin(), path.end()) << "\n";

  return 0;
}
