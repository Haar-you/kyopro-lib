#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include <iostream>
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Combinatorics/bernoulli_number_fps.cpp"

using mint = ModInt<998244353>;
constexpr int PRIM_ROOT = 3;
using FPS = FormalPowerSeries<mint>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto ft = FactorialTable<mint>(N + 1);
  
  auto ntt = NumberTheoreticTransform<mint, PRIM_ROOT, 1 << 20>();
  FPS::convolve = [&](const auto &a, const auto &b){return ntt.run_convolution(a, b);};

  auto res = bernoulli_number_fps<FPS>(N, ft);
  std::cout << join(res.begin(), res.begin() + N + 1) << "\n";

  return 0;
}
