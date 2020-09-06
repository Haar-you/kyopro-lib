#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <iostream>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/articulation_points.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  g.read<0, false, false>(E);

  auto ans = articulation_points(g);
  std::sort(ans.begin(), ans.end());

  for(auto x : ans) std::cout << x << std::endl;

  return 0;
}
