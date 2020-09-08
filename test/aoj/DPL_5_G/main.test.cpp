#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Combinatorics/bell_number.cpp"

namespace hl = haar_lib;

using mint = hl::ModInt<1000000007>;

int main(){
  auto ft = hl::FactorialTable<mint>(3000);

  int N, K; std::cin >> N >> K;

  std::cout << hl::bell_number(N, K, ft) << std::endl;

  return 0;
}
