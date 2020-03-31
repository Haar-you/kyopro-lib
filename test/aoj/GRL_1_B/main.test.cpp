#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/bellman_ford.cpp"

int main(){
  int V, E, r; std::cin >> V >> E >> r;

  Graph<int64_t> g(V);
  for(int i = 0; i < E; ++i){
    int s, t; std::cin >> s >> t;
    int64_t d; std::cin >> d;
    add_edge(g, s, t, d);
  }

  auto res = BellmanFord(g, r);
  
  bool neg_cycle = false;

  for(auto &x : res.dist){
    if(x.is_negloop()) neg_cycle = true;
  }

  if(neg_cycle){
    std::cout << "NEGATIVE CYCLE" << std::endl;
  }else{
    for(auto &x : res.dist){
      if(x.is_unreachable()){
        std::cout << "INF" << std::endl;
      }else{
        std::cout << x.value << std::endl;
      }
    }
  }

  return 0;
}
