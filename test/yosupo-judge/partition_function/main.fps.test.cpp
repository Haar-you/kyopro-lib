#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/partition_number_fps.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/IO/join.cpp"

using mint = ModInt<998244353>;
constexpr int PRIM = 3;
using FPS = FormalPowerSeries<mint>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto ntt = NumberTheoreticTransform<mint,PRIM,1<<20>();
  FPS::convolve =
    [&](const auto &a, const auto &b){
      return ntt.run_convolution(a, b);
    };

  auto ans = partition_number<FPS>(N);
  std::cout << join(ans.begin(), ans.begin() + (N + 1)) << "\n";

  return 0;
}
