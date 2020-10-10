#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Combinatorics/stirling_number_second.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;
const static auto ft = hl::factorial_table<mint>(3000);

int main(){
  int N, K; std::cin >> N >> K;

  std::cout << hl::stirling_number_of_second_kind<ft>(N, K) << std::endl;

  return 0;
}
