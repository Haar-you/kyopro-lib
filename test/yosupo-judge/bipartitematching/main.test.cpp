#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <iostream>
#include "Mylib/Graph/Matching/hopcroft_karp.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int L, R, M; std::cin >> L >> R >> M;
  hl::hopcroft_karp hk(L, R);

  for(auto [a, b] : hl::input_tuples<int, int>(M)){
    hk.add_edge(a, b);
  }

  hk.match();

  auto ans = hk.get_matching();

  std::cout << ans.size() << "\n";
  for(auto &[i, j] : ans){
    std::cout << i << " " << j << "\n";
  }

  return 0;
}
