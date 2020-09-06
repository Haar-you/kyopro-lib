#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <iostream>
#include <vector>
#include <functional>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"

using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;
using NTT = NumberTheoreticTransform<mint, 3, 1 << 20>;

int main(){
  using namespace std::placeholders;
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  auto ntt = NTT();
  FPS::convolve = std::bind(&NTT::convolve<mint>, &ntt, _1, _2);

  int N; std::cin >> N;
  auto a = input_vector<mint>(N);
  auto ans = FPS(a).inv();

  std::cout << join(ans.begin(), ans.begin() + N) << "\n";

  return 0;
}
