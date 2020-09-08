#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;

  hl::Graph<int> g(N);
  g.read<0, false, false>(M);

  auto res = hl::two_edge_connected_components(g);

  std::cout << res.size() << std::endl;
  for(auto &v : res){
    std::cout << v.size() << " " << hl::join(v.begin(), v.end()) << "\n";
  }

  return 0;
}
