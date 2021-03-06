#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"

namespace hl = haar_lib;

constexpr int mod = 1000000007;
using mint        = hl::modint<mod>;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  auto a = hl::input_vector<mint>(n);
  auto b = hl::input_vector<mint>(m);

  auto ans = hl::convolve_general_mod<mint>(a, b);

  std::cout << hl::join(ans.begin(), ans.begin() + n + m - 1) << "\n";

  return 0;
}
