#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include <iostream>
#include <functional>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/polynomial_taylor_shift.cpp"

namespace hl = haar_lib;

using mint = hl::ModInt<998244353>;
using NTT = hl::NumberTheoreticTransform<mint, 3, 1 << 21>;

int main(){
  using namespace std::placeholders;
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, c; std::cin >> N >> c;
  auto a = hl::input_vector<mint>(N);

  auto ntt = NTT();
  auto convolve = std::bind(&NTT::convolve<mint>, &ntt, _1, _2);
  auto ans = hl::polynomial_taylor_shift(a, mint(c), convolve);

  std::cout << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}
