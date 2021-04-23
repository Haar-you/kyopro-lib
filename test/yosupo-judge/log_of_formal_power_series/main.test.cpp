#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include <functional>
#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/IO/input_vector.cpp"
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
  auto a   = hl::input_vector<mint>(N);
  auto ans = FPS(a).log();

  std::cout << hl::join(ans.begin(), ans.begin() + N) << "\n";

  return 0;
}
