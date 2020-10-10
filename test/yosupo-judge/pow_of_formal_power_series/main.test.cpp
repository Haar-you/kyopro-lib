#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include <iostream>
#include <vector>
#include <functional>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;
using NTT = hl::number_theoretic_transform<mint, 3, 1 << 21>;
const static auto ntt = NTT();
using FPS = hl::formal_power_series<mint, ntt>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;
  auto a = hl::input_vector<mint>(N);
  auto ans = FPS(a).pow(M);

  std::cout << hl::join(ans.begin(), ans.begin() + N) << "\n";

  return 0;
}
