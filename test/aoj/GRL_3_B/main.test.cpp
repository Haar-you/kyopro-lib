#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <iostream>
#include <algorithm>
#include <utility>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/bridges.cpp"

namespace hl = haar_lib;

int main(){
  int V, E; std::cin >> V >> E;

  hl::Graph<int> g(V);
  g.read<0, false, false>(E);

  auto ans = hl::bridges(g);
  for(auto &e : ans) if(e.from > e.to) std::swap(e.from, e.to);

  std::sort(
    ans.begin(), ans.end(),
    [](const auto &a, const auto &b){
      if(a.from != b.from) return a.from < b.from;
      return a.to < b.to;
    }
  );

  for(auto &e :ans) std::cout << e.from << " " << e.to << std::endl;

  return 0;
}
