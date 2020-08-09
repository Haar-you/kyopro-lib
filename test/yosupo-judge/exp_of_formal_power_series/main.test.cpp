#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include <iostream>
#include <vector>

#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Convolution/formal_power_series.cpp"
#include "Mylib/IO/input_vector.cpp"

using mint = ModInt<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  auto ntt = NumberTheoreticTransform<mint, 3, 1<<21>();
  
  FPS<mint>::convolve =
    [&](const auto &a, const auto &b){
      return ntt.run_convolution(a, b);
    };

  int N; std::cin >> N;

  auto a = input_vector<mint>(N);

  FPS<mint> f(a);
  auto ans = f.exp();

  for(int i = 0; i < N; ++i) std::cout << ans[i] << " ";
  std::cout << std::endl;

  return 0;
}
