#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include <iostream>
#include "Mylib/Convolution/convolution_xor.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"

namespace hl = haar_lib;

constexpr int mod = 998244353;
using mint        = hl::modint<mod>;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N;
  std::cin >> N;
  const auto a = hl::input_vector<mint>(1 << N);
  const auto b = hl::input_vector<mint>(1 << N);

  const auto ans = convolution_xor(a, b);
  std::cout << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}
