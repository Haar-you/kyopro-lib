#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <iostream>
#include "Mylib/Graph/Matching/hopcroft_karp.cpp"

int main(){
  int L,R,M; std::cin >> L >> R >> M;
  HopcroftKarp hk(L,R);

  for(int i = 0; i < M; ++i){
    int a, b; std::cin >> a >> b;
    hk.add_edge(a, b);
  }
  
  hk.solve();

  auto ans = hk.get_matching();

  std::cout << ans.size() << std::endl;
  for(auto &[i,j] : ans){
    std::cout << i << " " << j << std::endl;
  }

  return 0;
}
