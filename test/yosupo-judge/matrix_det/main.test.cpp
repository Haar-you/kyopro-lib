#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/determinant.cpp"
#include "Mylib/IO/input_vector.cpp"

using mint = ModInt<998244353>;

struct tag {};
using Mat = SquareMatrix<mint, tag>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  Mat::init(N);

  Mat m(input_vector<mint>(N, N));

  std::cout << determinant(m) << "\n";

  return 0;
}
