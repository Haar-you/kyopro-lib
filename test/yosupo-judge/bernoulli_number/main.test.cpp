#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include <iostream>
#include <functional>
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Number/Prime/primitive_root.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Combinatorics/bernoulli_number_fps.cpp"

namespace hl = haar_lib;

constexpr int mod = 998244353;
constexpr int prim_root = hl::primitive_root(mod);
using mint = hl::modint<mod>;
using NTT = hl::number_theoretic_transform<mint, prim_root, 1 << 20>;
const static auto ft = hl::factorial_table<mint>(500001);
const static auto ntt = NTT();
using FPS = hl::formal_power_series<mint, ntt>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto res = hl::bernoulli_number_fps<FPS, ft>(N);
  std::cout << hl::join(res.begin(), res.begin() + N + 1) << "\n";

  return 0;
}
