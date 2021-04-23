#define PROBLEM "https://yukicoder.me/problems/no/194"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/LinearAlgebra/inverse_matrix.cpp"
#include "Mylib/LinearAlgebra/square_matrix.cpp"
#include "Mylib/Number/Mint/mint.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;

static int N;
using M = hl::square_matrix_dyn<mint, N>;

std::pair<mint, mint> solve1(int64_t N, int64_t K, std::vector<int> A) {
  M m;

  for (int i = 0; i < N; ++i) m[0][i] = 1;
  for (int i = 0; i < N - 1; ++i) m[i + 1][i] = 1;

  std::reverse(A.begin(), A.end());

  mint f = 0;

  {
    auto m2 = m.pow(K - N);
    for (int i = 0; i < N; ++i) f += m2[0][i] * A[i];
  }

  mint s = std::accumulate(A.begin(), A.end(), mint(0));

  {
    auto c    = hl::inverse_matrix(M::unit() - m).value();
    auto temp = (M::unit() - m.pow(K - N + 1)) * c - M::unit();

    s += dot(temp[0], M::vector_type(A));
  }

  return {f, s};
}

std::pair<mint, mint> solve2(int64_t N, int64_t K, std::vector<int> A) {
  std::vector<mint> v(K);

  mint temp = 0;
  for (int i = 0; i < N; ++i) {
    temp += A[i];
    v[i] = A[i];
  }

  for (int i = N; i < K; ++i) {
    v[i] = temp;
    temp += v[i];
    temp -= v[i - N];
  }

  mint f = v.back();
  mint s = std::accumulate(v.begin(), v.end(), mint(0));

  return {f, s};
}

int main() {
  int64_t K;
  std::cin >> N >> K;

  auto A = hl::input_vector<int>(N);

  auto [f, s] = K > 1000000 ? solve1(N, K, A) : solve2(N, K, A);
  std::cout << f << " " << s << "\n";

  return 0;
}
