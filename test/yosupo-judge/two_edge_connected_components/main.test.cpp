#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;

  auto g = convert_to_graph<int, false>(N, input_edges<int, 0, false>(M));

  auto res = two_edge_connected_components(g);

  std::cout << res.size() << std::endl;
  for(auto &v : res){
    std::cout << v.size() << " " << join(v.begin(), v.end()) << "\n";
  }

  return 0;
}
