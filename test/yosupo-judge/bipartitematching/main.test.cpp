#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <iostream>
#include "Mylib/Graph/Matching/hopcroft_karp.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int L,R,M; std::cin >> L >> R >> M;
  HopcroftKarp hk(L,R);

  for(auto [a, b] : input_tuples<int, int>(M)){
    hk.add_edge(a, b);
  }
  
  hk.solve();

  auto ans = hk.get_matching();

  std::cout << ans.size() << "\n";
  for(auto &[i,j] : ans){
    std::cout << i << " " << j << "\n";
  }

  return 0;
}
