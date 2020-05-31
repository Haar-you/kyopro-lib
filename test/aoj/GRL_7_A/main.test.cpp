#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include <iostream>
#include "Mylib/Graph/Matching/bipartite_matching.cpp"
#include "Mylib/Graph/Flow/ford_fulkerson.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int X, Y, E; std::cin >> X >> Y >> E;

  BipartiteMatching<FordFulkerson<int>> b(X, Y);

  for(auto [x, y] : input_tuples<int, int>(E)){
    b.add_edge(x, y);
  }

  int ans = b.solve();

  std::cout << ans << std::endl;

  return 0;
}
