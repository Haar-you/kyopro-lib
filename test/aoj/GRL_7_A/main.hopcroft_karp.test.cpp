#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include <iostream>
#include "Mylib/Graph/Matching/hopcroft_karp.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int X, Y, E; std::cin >> X >> Y >> E;

  hl::hopcroft_karp b(X, Y);

  for(auto [x, y] : hl::input_tuples<int, int>(E)){
    b.add_edge(x, y);
  }

  int ans = b.match();

  std::cout << ans << std::endl;

  return 0;
}
