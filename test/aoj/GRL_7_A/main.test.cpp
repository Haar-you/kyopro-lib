#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include <iostream>
#include "Mylib/Graph/Matching/bipartite_matching.cpp"

int main(){
  int X, Y, E; std::cin >> X >> Y >> E;

  BipartiteMatching b(X, Y);

  for(int i = 0; i < E; ++i){
    int x, y; std::cin >> x >> y;
    b.add_edge(x, y);
  }

  int ans = b.solve();

  std::cout << ans << std::endl;

  return 0;
}
