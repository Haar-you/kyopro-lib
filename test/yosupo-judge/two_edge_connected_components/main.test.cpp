#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;

  Graph<int> g(N);
  for(int i = 0; i < M; ++i){
    int a, b; std::cin >> a >> b;
    add_undirected(g, a, b, 1);
  }

  auto res = two_edge_connected_components(g);

  std::cout << res.size() << std::endl;
  for(auto &v : res){
    std::cout << v.size();
    for(auto x : v) std::cout << " " << x;
    std::cout << std::endl;
  }

  return 0;
}
