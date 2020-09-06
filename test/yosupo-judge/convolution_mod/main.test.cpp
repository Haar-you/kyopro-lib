#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

const int mod = 998244353;
const int PRIM_ROOT = 3;

using mint = ModInt<mod>;
using NTT = NumberTheoreticTransform<mint, PRIM_ROOT, 1 << 20>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m; std::cin >> n >> m;

  auto a = input_vector<int64_t>(n);
  auto b = input_vector<int64_t>(m);

  auto ntt = NTT();
  auto ans = ntt.convolve(a, b);

  std::cout << join(ans.begin(), ans.begin() + n + m - 1) << "\n";

  return 0;
}

