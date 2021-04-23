#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include <iostream>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Math/linearly_recurrent_sequence.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Number/Prime/primitive_root.cpp"

namespace hl = haar_lib;

constexpr int mod       = 998244353;
constexpr int prim_root = hl::primitive_root(mod);
using mint              = hl::modint<mod>;
using NTT               = hl::number_theoretic_transform<mint, prim_root, 1 << 21>;
const static auto ntt   = NTT();

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int d;
  std::cin >> d;
  int64_t k;
  std::cin >> k;

  auto a = hl::input_vector<mint>(d);
  auto c = hl::input_vector<mint>(d);
  std::reverse(c.begin(), c.end());

  auto ans = hl::linearly_recurrent_sequence<mint, ntt>(a, c, k);

  std::cout << ans << "\n";

  return 0;
}
