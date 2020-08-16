#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include <iostream>
#include <vector>

#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Number/Mod/mod_sqrt.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"

using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  auto ntt = NumberTheoreticTransform<mint, 3, 1<<21>();
  
  FPS::convolve =
    [&](const auto &a, const auto &b){
      return ntt.run_convolution(a, b);
    };

  FPS::get_sqrt =
    [&](const auto &a){
      return mod_sqrt(a.val, mint::MOD);
    };

  int N; std::cin >> N;

  auto a = input_vector<mint>(N);

  FPS f(a);
  auto ans = f.sqrt();

  if(ans){
    std::cout << join((*ans).begin(), (*ans).begin() + N) << "\n";
  }else{
    std::cout << -1 << "\n";
  }

  return 0;
}
