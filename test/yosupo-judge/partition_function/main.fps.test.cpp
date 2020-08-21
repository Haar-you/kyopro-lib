#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include <functional>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/partition_number_fps.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/IO/join.cpp"

constexpr int PRIM = 3;
using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;
using NTT = NumberTheoreticTransform<mint,PRIM,1<<20>;

int main(){
  using namespace std::placeholders;
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto ntt = NTT();
  FPS::convolve = std::bind(&NTT::convolve<mint>, &ntt, _1, _2);

  auto ans = partition_number<FPS>(N);
  std::cout << join(ans.begin(), ans.begin() + (N + 1)) << "\n";

  return 0;
}
