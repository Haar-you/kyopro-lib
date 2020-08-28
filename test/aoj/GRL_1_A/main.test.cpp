#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/ShortestPath/dijkstra.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int V, E, r; std::cin >> V >> E >> r;

  Graph<int64_t> g(V);
  g.read<0>(E);

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
