#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"

#include <iostream>
#include <functional>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Combinatorics/stirling_number_first_fft.cpp"
#include "Mylib/IO/join.cpp"

constexpr int MOD = 998244353;
constexpr int PRIM = 3;

using mint = ModInt<MOD>;
using NTT = NumberTheoreticTransform<mint, PRIM, 1 << 20>;

int main(){
  using namespace std::placeholders;
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto ntt = NTT();
  auto convolve = std::bind(&NTT::convolve<mint>, &ntt, _1, _2);
  auto res = stirling_number_of_first_kind_fft<mint>(N, convolve);

  std::cout << join(res.begin(), res.end()) << "\n";

  return 0;
}
