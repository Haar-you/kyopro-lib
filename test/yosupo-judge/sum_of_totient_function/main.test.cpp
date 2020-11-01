#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Number/Totient/totient_sum.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int64_t N; std::cin >> N;

  std::cout << hl::totient_sum<mint>(N) << "\n";

  return 0;
}
