#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/bell_number_table.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;

int main(){
  int N, K; std::cin >> N >> K;

  auto table = hl::bell_number_table<mint>(std::max(N, K));

  std::cout << table[N][K] << std::endl;

  return 0;
}
