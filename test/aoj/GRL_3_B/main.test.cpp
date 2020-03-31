#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <iostream>
#include <algorithm>
#include <utility>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/bridges.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s, t; std::cin >> s >> t;
    add_undirected(g, s, t, 1);
  }

  auto ans = bridges(g);
  for(auto &e : ans) if(e.from > e.to) std::swap(e.from, e.to);
  
  std::sort(ans.begin(), ans.end(),
       [](const auto &a, const auto &b){
         if(a.from != b.from) return a.from < b.from;
         return a.to < b.to;
       });

  for(auto &e :ans) std::cout << e.from << " " << e.to << std::endl;
  
  return 0;
}
