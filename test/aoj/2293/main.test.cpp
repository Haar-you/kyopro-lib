#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2293"

#include <iostream>
#include <vector>
#include "Mylib/Graph/Matching/weighted_bipartite_matching.cpp"
#include "Mylib/Graph/Flow/minimum_cost_flow.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;

  auto [A, B] = input_tuple_vector<int, int>(n);

  std::vector<int> ls(A);
  ls.insert(ls.end(), B.begin(), B.end());

  std::sort(ls.begin(), ls.end());
  ls.erase(std::unique(ls.begin(), ls.end()), ls.end());

  WeightedBipartiteMatching<int, MinimumCostFlow<int, int>> m(n, ls.size(), true);

  for(int i = 0; i < n; ++i){
    m.add_edge(i, std::lower_bound(ls.begin(), ls.end(), A[i]) - ls.begin(), B[i]);
    m.add_edge(i, std::lower_bound(ls.begin(), ls.end(), B[i]) - ls.begin(), A[i]);
  }

  int ans = m.solve(n);

  std::cout << ans << std::endl;

  return 0;
}
