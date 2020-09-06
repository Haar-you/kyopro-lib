#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include <iostream>

#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/enumerate_triangles.cpp"
#include "Mylib/Number/Mint/mint.cpp"

using mint = ModInt<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;
  auto x = input_vector<mint>(N);

  Graph<int> g(N);
  g.read<0, false, false>(M);

  auto res = enumerate_triangles(g);
  mint ans = 0;
  for(auto [i, j, k] : res) ans += x[i] * x[j] * x[k];

  std::cout << ans << "\n";

  return 0;
}
