#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

const int mod = 998244353;
const int PRIM_ROOT = 3;

using mint = hl::modint<mod>;
using NTT = hl::number_theoretic_transform<mint, PRIM_ROOT, 1 << 20>;
const static auto ntt = NTT();

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m; std::cin >> n >> m;

  auto a = hl::input_vector<int64_t>(n);
  auto b = hl::input_vector<int64_t>(m);

  auto ans = ntt(a, b);

  std::cout << hl::join(ans.begin(), ans.begin() + n + m - 1) << "\n";

  return 0;
}
