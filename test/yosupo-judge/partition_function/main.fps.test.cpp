#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <functional>
#include <iostream>
#include "Mylib/Combinatorics/partition_number_fps.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Number/Prime/primitive_root.cpp"

namespace hl = haar_lib;

constexpr int mod       = 998244353;
constexpr int prim_root = hl::primitive_root(mod);
using mint              = hl::modint<mod>;
using NTT               = hl::number_theoretic_transform<mint, prim_root, 1 << 20>;
const static auto ntt   = NTT();
using FPS               = hl::formal_power_series<mint, ntt>;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N;
  std::cin >> N;

  auto ans = hl::partition_number_fps<FPS>(N);
  std::cout << hl::join(ans.begin(), ans.begin() + (N + 1)) << "\n";

  return 0;
}
