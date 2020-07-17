#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include <iostream>
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/Graph/Cycle/detect_cycle.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;
  auto edges = input_edges<int, 0, false>(M);

  auto res = detect_cycle(N, M, edges);

  if(res){
    std::cout << (*res).size() << "\n";
    for(auto x : *res){
      std::cout << x << "\n";
    }
  }else{
    std::cout << -1 << "\n";
  }
  
  return 0;
}
