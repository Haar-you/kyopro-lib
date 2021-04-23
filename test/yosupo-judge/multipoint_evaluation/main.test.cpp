#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include <iostream>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Math/multipoint_evaluation.cpp"
#include "Mylib/Math/polynomial.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Number/Prime/primitive_root.cpp"

namespace hl = haar_lib;

constexpr int mod       = 998244353;
constexpr int prim_root = hl::primitive_root(mod);
using mint              = hl::modint<mod>;
const static auto ntt   = hl::number_theoretic_transform<mint, prim_root, 1 << 20>();
using poly              = hl::polynomial<mint, ntt>;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  auto c = hl::input_vector<mint>(N);
  auto p = hl::input_vector<mint>(M);

  auto ans = hl::multipoint_evaluation(poly(c), p);

  std::cout << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}
