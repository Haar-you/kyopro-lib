#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include <iostream>
#include <vector>
#include "Mylib/Graph/maximum_independent_set.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  int N,M; std::cin >> N >> M;
  std::vector<std::vector<int>> g(N, std::vector<int>(N));
  for(int i = 0; i < M; ++i){
    int u,v; std::cin >> u >> v;
    g[u][v] = g[v][u] = 1;
  }

  auto res = maximum_independent_set(g);

  std::vector<int> ans;
  for(int i = 0; i < N; ++i){
    if(res & (1LL << i)) ans.push_back(i);
  }

  std::cout << ans.size() << " " << join(ans.begin(), ans.end()) << "\n";
  
  return 0;
}
