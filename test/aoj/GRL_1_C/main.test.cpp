#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/warshall_floyd.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  auto g = convert_to_graph<int, true>(V, input_edges<int, 0, true>(E));

  auto res = WarshallFloyd<int>(g);
  
  if(res.has_negative_cycle){
    std::cout << "NEGATIVE CYCLE" << std::endl;
  }else{
    for(int i = 0; i < V; ++i){
      for(int j = 0; j < V; ++j){
        if(j) std::cout << " ";
        auto &ans = res.dist[i][j];
        if(ans){
          std::cout << *ans;
        }else{
          std::cout << "INF";
        }
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
