#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit"

#include <iostream>
#include "Mylib/Math/sum_of_exponential_times_polynomial_limit.cpp"
#include "Mylib/Number/Mint/mint.cpp"

namespace hl = haar_lib;

constexpr int mod = 998244353;
using mint        = hl::modint<mod>;

int main() {
  int r, d;
  std::cin >> r >> d;
  std::cout << hl::sum_of_exponential_times_polynomial_limit<mint>(r, d) << "\n";

  return 0;
}
