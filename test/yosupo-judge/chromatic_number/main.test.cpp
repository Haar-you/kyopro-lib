#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include <iostream>
#include <vector>
#include "Mylib/Graph/Coloring/chromatic_number.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;
  std::vector<std::vector<int>> g(N);

  for(int i = 0; i < M; ++i){
    int u, v; std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int ans = hl::chromatic_number(g);
  std::cout << ans << "\n";

  return 0;
}
