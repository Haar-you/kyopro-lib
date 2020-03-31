#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/stirling_number_table.cpp"

using mint = ModInt<1000000007>;

int main(){
  int N, K; std::cin >> N >> K;

  auto table = stirling_number_table<mint>(std::max(N, K));

  std::cout << table[N][K] << std::endl;

  return 0;
}
