#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <iostream>
#include <vector>
#include "Mylib/Graph/Matching/weighted_bipartite_matching.cpp"
#include "Mylib/Graph/Flow/minimum_cost_flow.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;
  WeightedBipartiteMatching<int64_t, MinimumCostFlow<int, int64_t>, true> m(N, N);

  auto a = input_vector<int64_t>(N, N);

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      m.add_edge(i, j, a[i][j]);
    }
  }

  auto ans = m.solve(N);
  std::cout << ans << std::endl;

  auto matching = m.get_matching();

  std::vector<int> p(N);
  for(auto [i, j, c] : matching){
    p[i] = j;
  }

  std::cout << join(p.begin(), p.end()) << "\n";

  return 0;
}
