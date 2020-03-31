#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <iostream>
#include <climits>
#include "Mylib/Graph/Flow/dinic.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Dinic<int, INT_MAX> f(V);
  for(int i = 0; i < E; ++i){
    int s, t, c; std::cin >> s >> t >> c;

    f.add_edge(s, t, c);
  }

  auto ans = f.solve(0, V-1);
  std::cout << ans << std::endl;

  return 0;
}
