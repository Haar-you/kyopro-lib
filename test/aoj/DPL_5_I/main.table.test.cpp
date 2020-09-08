#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/stirling_number_second_table.cpp"

namespace hl = haar_lib;

using mint = hl::ModInt<1000000007>;

int main(){
  int N, K; std::cin >> N >> K;

  auto table = hl::stirling_number_of_second_kind_table<mint>(std::max(N, K));

  std::cout << table[N][K] << std::endl;

  return 0;
}
