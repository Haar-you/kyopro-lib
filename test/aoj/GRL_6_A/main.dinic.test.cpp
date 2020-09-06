#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <iostream>
#include <climits>
#include "Mylib/Graph/Flow/dinic.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Dinic<int> f(V);

  for(auto [s, t, c] : input_tuples<int, int, int>(E)){
    f.add_edge(s, t, c);
  }

  auto ans = f.solve(0, V - 1);
  std::cout << ans << std::endl;

  return 0;
}
