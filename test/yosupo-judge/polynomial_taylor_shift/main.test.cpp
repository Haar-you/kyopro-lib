#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include <iostream>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Convolution/polynomial_taylor_shift.cpp"

using mint = ModInt<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  auto ntt = NumberTheoreticTransform<mint, 3, 1<<21>();
  auto ft = FactorialTable<mint>(600000);

  int N, c; std::cin >> N >> c;
  auto a = input_vector<mint>(N);

  auto ans = polynomial_taylor_shift(a, mint(c), ft, [&](const auto &x, const auto &y){return ntt.run_convolution(x, y);});

  std::cout << join(ans.begin(), ans.end()) << "\n";
  
  return 0;
}
