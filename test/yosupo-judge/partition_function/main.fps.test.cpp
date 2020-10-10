#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include <functional>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/partition_number_fps.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

constexpr int PRIM = 3;
using mint = hl::modint<998244353>;
using NTT = hl::number_theoretic_transform<mint, PRIM, 1 << 20>;
const static auto ntt = NTT();
using FPS = hl::formal_power_series<mint, ntt>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto ans = hl::partition_number_fps<FPS>(N);
  std::cout << hl::join(ans.begin(), ans.begin() + (N + 1)) << "\n";

  return 0;
}
