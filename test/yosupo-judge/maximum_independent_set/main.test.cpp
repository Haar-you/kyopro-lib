#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include <iostream>
#include <vector>
#include "Mylib/Graph/maximum_independent_set.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int N, M; std::cin >> N >> M;
  std::vector<std::vector<int>> g(N, std::vector<int>(N));
  for(auto [u, v] : hl::input_tuples<int, int>(M)){
    g[u][v] = g[v][u] = 1;
  }

  auto res = hl::maximum_independent_set(g);

  std::vector<int> ans;
  for(int i = 0; i < N; ++i){
    if(res & (1LL << i)) ans.push_back(i);
  }

  std::cout << ans.size() << " " << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}
