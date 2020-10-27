#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Number/Prime/primitive_root.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Combinatorics/stirling_number_second_fft.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

constexpr int mod = 998244353;
constexpr int prim_root = hl::primitive_root(mod);

using mint = hl::modint<mod>;
using NTT = hl::number_theoretic_transform<mint, prim_root, 1 << 20>;
const auto ntt = NTT();

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto res = hl::stirling_number_of_second_kind_fft<mint>(N, ntt);
  std::cout << hl::join(res.begin(), res.end()) << "\n";

  return 0;
}
