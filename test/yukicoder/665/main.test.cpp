#define PROBLEM "https://yukicoder.me/problems/no/665"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Combinatorics/bernoulli_number.cpp"

namespace hl = haar_lib;

using mint = hl::ModInt<1000000007>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int64_t n, k; std::cin >> n >> k;
  auto ft = hl::FactorialTable<mint>(3 * k);

  auto b = hl::bernoulli_number(k, ft);

  mint ans = 0;

  for(int64_t i = 0; i <= k; ++i){
    ans += ft.C(k + 1, i) * b[i] * mint::power(n + 1, k + 1 - i);
  }

  ans /= k + 1;

  std::cout << ans << std::endl;

  return 0;
}
