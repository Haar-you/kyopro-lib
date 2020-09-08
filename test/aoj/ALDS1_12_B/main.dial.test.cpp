#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/ShortestPath/dial_algorithm.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;
  hl::Graph<int> g(n);

  for(int i = 0; i < n; ++i){
    int u, k; std::cin >> u >> k;
    for(int j = 0; j < k; ++j){
      int v, c; std::cin >> v >> c;
      g.add_edge(u, v, c);
    }
  }

  auto ans = hl::dial_algorithm(g, {0}, 100000);

  for(int i = 0; i < n; ++i) std::cout << i << " " << *ans[i] << "\n";

  return 0;
}
