#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include <iostream>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/polynomial_taylor_shift.cpp"

using mint = ModInt<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  auto ntt = NumberTheoreticTransform<mint, 3, 1<<21>();

  int N, c; std::cin >> N >> c;
  auto a = input_vector<mint>(N);

  auto convolve = [&](const auto &x, const auto &y){return ntt.run_convolution(x, y);};
  auto ans = polynomial_taylor_shift(a, mint(c), convolve);

  std::cout << join(ans.begin(), ans.end()) << "\n";
  
  return 0;
}
