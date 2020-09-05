#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/ShortestPath/bellman_ford.cpp"

int main(){
  int V, E, r; std::cin >> V >> E >> r;

  Graph<int64_t> g(V);
  g.read<0>(E);

  auto res = bellman_ford(g, r);

  bool neg_cycle = false;

  for(auto &x : res){
    if(x.is_negloop()) neg_cycle = true;
  }

  if(neg_cycle){
    std::cout << "NEGATIVE CYCLE" << std::endl;
  }else{
    for(auto &x : res){
      if(x.is_unreachable()){
        std::cout << "INF" << std::endl;
      }else{
        std::cout << x.value() << std::endl;
      }
    }
  }

  return 0;
}
