#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include <iostream>

#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/TypicalProblem/SubsetSumProblem/subset_sum_count_fps.cpp"

using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, T; std::cin >> N >> T;
  auto s = input_vector<int>(N);

  auto ntt = NumberTheoreticTransform<mint, 3, 1<<21>();
  
  FPS::convolve =
    [&](const auto &a, const auto &b){
      return ntt.run_convolution(a, b);
    };

  auto ans = subset_sum_count_fps<FPS>(s, T);  
  
  std::cout << join(ans.begin() + 1, ans.begin() + T + 1) << "\n";
  
  return 0;
}

