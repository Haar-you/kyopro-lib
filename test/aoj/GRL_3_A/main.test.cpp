#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/articulation_points.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s, t; std::cin >> s >> t;
    add_undirected(g, s, t, 1);
  }

  auto ans = articulation_points(g);
  sort(ans.begin(), ans.end());
  
  for(auto x : ans) std::cout << x << std::endl;

  return 0;
}
