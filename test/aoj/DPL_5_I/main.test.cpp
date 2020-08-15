#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Combinatorics/stirling_number.cpp"

using mint = ModInt<1000000007>;
 
int main(){
  auto ft = FactorialTable<mint>(3000);

  int N, K; std::cin >> N >> K;

  std::cout << stirling_number<mint>(ft, N, K) << std::endl;

  return 0;
}
