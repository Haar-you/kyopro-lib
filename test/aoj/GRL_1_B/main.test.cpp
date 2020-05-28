#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/bellman_ford.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int V, E, r; std::cin >> V >> E >> r;

  auto g = convert_to_graph<int64_t, true>(V, input_edges<int64_t, 0, true>(E));

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
        std::cout << x.value() << std::endl;
      }
    }
  }

  return 0;
}
