#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/dial_algorithm.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;
  Graph<int> g(n);

  for(int i = 0; i < n; ++i){
    int u, k; std::cin >> u >> k;
    for(int j = 0; j < k; ++j){
      int v, c; std::cin >> v >> c;
      add_edge(g, u, v, c);
    }
  }

  auto ans = dial_algorithm(g, {0}, 100000);

  for(int i = 0; i < n; ++i) std::cout << i << " " << *ans[i] << "\n";

  return 0;
}
