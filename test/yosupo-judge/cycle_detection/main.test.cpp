#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#define IGNORE

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/Cycle/detect_cycle.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;
  Graph<int> g(N);
  g.read<0, true, false>(M);

  auto res = detect_cycle(g);

  if(res){
    std::cout << (*res).size() << "\n";
    for(auto &e : *res){
      std::cout << e.index << "\n";
    }
  }else{
    std::cout << -1 << "\n";
  }

  return 0;
}
