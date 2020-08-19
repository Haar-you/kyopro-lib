#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/stirling_number_second_fft.cpp"
#include "Mylib/IO/join.cpp"

const int MOD = 998244353;
const int PRIM = 3;

using mint = ModInt<MOD>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto ntt = NumberTheoreticTransform<mint,PRIM,1<<20>();
  auto convolve = [&](const auto &a, const auto &b){return ntt.run_convolution(a, b);};
  auto res = stirling_number_of_second_kind<mint>(N, convolve);

  std::cout << join(res.begin(), res.end()) << "\n";

  return 0;
}
