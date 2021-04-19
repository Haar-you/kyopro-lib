#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <iostream>

#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/matrix.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M, K; std::cin >> N >> M >> K;

  auto a = hl::matrix(hl::input_vector<mint>(N, M));
  auto b = hl::matrix(hl::input_vector<mint>(M, K));

  auto c = a * b;

  for(int i = 0; i < N; ++i){
    std::cout << hl::join(c[i].begin(), c[i].end()) << "\n";
  }

  return 0;
}
