#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"

#include <iostream>
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto [x, y] = input_tuple_vector<int64_t, int64_t>(N);

  auto res = manhattan_minimum_spanning_tree(x, y);

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
