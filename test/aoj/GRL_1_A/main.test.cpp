#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/dijkstra.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int V, E, r; std::cin >> V >> E >> r;

  Graph<int64_t> g(V);
  for(int i = 0; i < E; ++i){
    int s, t; std::cin >> s >> t;
    int64_t d; std::cin >> d;
    add_edge(g, s, t, d);
  }

  auto res = Dijkstra<int64_t>(g, r);
  
  for(auto x : res.dist){
    if(not x){
      std::cout << "INF" << std::endl;
    }else{
      std::cout << *x << std::endl;
    }
  }
  
  return 0;
}
