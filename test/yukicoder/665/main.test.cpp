#define PROBLEM "https://yukicoder.me/problems/no/665"

#include <iostream>

#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/combinatorics.cpp"
#include "Mylib/Combinatorics/bernoulli_number.cpp"

using mint = ModInt<1000000007>;
using C = Combinatorics<mint>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int64_t n, k; std::cin >> n >> k;
  C::init(3*k);

  auto b = C::bernoulli_number(k);

  mint ans = 0;

  for(int64_t i = 0; i <= k; ++i){
    ans += C::C(k+1, i) * b[i] * mint::power(n+1, k+1-i);
  }
  
  ans /= k+1;

  std::cout << ans << std::endl;
  
  return 0;
}