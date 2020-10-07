#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/ShortestPath/bellman_ford.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int V, E, r; std::cin >> V >> E >> r;

  hl::graph<int64_t> g(V);
  g.read<0>(E);

  auto res = hl::bellman_ford(g, r);

  bool neg_cycle = std::any_of(res.begin(), res.end(), [](const auto &a){return a.is_negative_inf();});

  if(neg_cycle){
    std::cout << "NEGATIVE CYCLE" << std::endl;
  }else{
    for(auto &x : res){
      if(x.is_positive_inf()){
        std::cout << "INF" << std::endl;
      }else{
        std::cout << x.value() << std::endl;
      }
    }
  }

  return 0;
}
