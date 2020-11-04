#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include <iostream>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Number/Prime/primitive_root.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/polynomial_taylor_shift.cpp"

namespace hl = haar_lib;

constexpr int mod = 998244353;
constexpr int prim_root = hl::primitive_root(mod);
using mint = hl::modint<mod>;
using NTT = hl::number_theoretic_transform<mint, prim_root, 1 << 21>;
const static auto ntt = NTT();

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, c; std::cin >> N >> c;
  auto a = hl::input_vector<mint>(N);

  auto ans = hl::polynomial_taylor_shift<mint, ntt>(a, c);
  std::cout << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}
