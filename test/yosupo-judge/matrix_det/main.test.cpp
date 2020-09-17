#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/determinant.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;

static int N;
using Mat = hl::square_matrix<mint, N>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  Mat m(hl::input_vector<mint>(N, N));

  std::cout << hl::determinant(m) << "\n";

  return 0;
}
