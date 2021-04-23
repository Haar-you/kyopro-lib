#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <iostream>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/LinearAlgebra/determinant.cpp"
#include "Mylib/LinearAlgebra/square_matrix.cpp"
#include "Mylib/Number/Mint/mint.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;

static int N;
using Mat = hl::square_matrix_dyn<mint, N>;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  Mat m(hl::input_vector<mint>(N, N));

  std::cout << hl::determinant(m) << "\n";

  return 0;
}
