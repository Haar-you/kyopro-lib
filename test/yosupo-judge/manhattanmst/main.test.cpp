#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"

#include <iostream>
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp"
#include "Mylib/Graph/MinimumSpanningTree/kruskal.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto [x, y] = hl::input_tuple_vector<int64_t, int64_t>(N);

  auto res = hl::manhattan_minimum_spanning_tree(x, y, hl::kruskal<int64_t>);

  int64_t ans = 0;

  for(auto &e : res){
    ans += e.cost;
  }

  std::cout << ans << "\n";
  for(auto &e : res){
    std::cout << e.from << " " << e.to << "\n";
  }

  return 0;
}
