#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/tree_diameter.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;

  Tree<int64_t> tree(N);
  for(int i = 0; i < N-1; ++i){
    int a, b; std::cin >> a >> b;
    int64_t c; std::cin >> c;
    add_undirected(tree, a, b, c);
  }

  auto [cost, path] = tree_diameter(tree);

  std::cout << cost << " " << path.size() << "\n";
  for(int x : path) std::cout << x << " ";
  std::cout << "\n";

  return 0;
}
