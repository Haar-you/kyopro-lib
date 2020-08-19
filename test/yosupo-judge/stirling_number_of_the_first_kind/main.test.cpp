#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"
#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Combinatorics/stirling_number_first_fft.cpp"
#include "Mylib/IO/join.cpp"

using mint = ModInt<998244353>;
constexpr int PRIM = 3;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto ntt = NumberTheoreticTransform<mint,PRIM,1<<20>();
  auto convolve = [&](const auto &a, const auto &b){return ntt.run_convolution(a, b);};
  auto res = stirling_number_of_first_kind<mint>(N, convolve);

  std::cout << join(res.begin(), res.end()) << "\n";

  return 0;
}

