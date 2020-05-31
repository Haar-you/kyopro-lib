#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <iostream>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/articulation_points.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  auto g = convert_to_graph<int, false>(V, input_edges<int, 0, false>(E));

  auto ans = articulation_points(g);
  std::sort(ans.begin(), ans.end());
  
  for(auto x : ans) std::cout << x << std::endl;

  return 0;
}
