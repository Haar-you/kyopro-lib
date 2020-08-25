#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/dijkstra.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int V, E, r; std::cin >> V >> E >> r;

  auto g = convert_to_graph<int64_t, true>(V, input_edges<int64_t, 0, true>(E));

  auto res = dijkstra(g, {r});
  
  for(auto x : res){
    if(not x){
      std::cout << "INF" << std::endl;
    }else{
      std::cout << *x << std::endl;
    }
  }
  
  return 0;
}
