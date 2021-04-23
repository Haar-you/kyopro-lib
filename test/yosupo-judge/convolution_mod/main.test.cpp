#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Number/Prime/primitive_root.cpp"

namespace hl = haar_lib;

constexpr int mod       = 998244353;
constexpr int prim_root = hl::primitive_root(mod);

using mint            = hl::modint<mod>;
using NTT             = hl::number_theoretic_transform<mint, prim_root, 1 << 20>;
const static auto ntt = NTT();

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  auto a = hl::input_vector<int64_t>(n);
  auto b = hl::input_vector<int64_t>(m);

  auto ans = ntt(a, b);

  std::cout << hl::join(ans.begin(), ans.begin() + n + m - 1) << "\n";

  return 0;
}
