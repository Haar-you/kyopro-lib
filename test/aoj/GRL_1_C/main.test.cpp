#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/warshall_floyd.cpp"

int main(){
  int V, E; std::cin >> V >> E;
  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s,t,d; std::cin >> s >> t >> d;
    add_edge(g, s, t, d);
  }

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
