#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/partition_number.cpp"

namespace hl = haar_lib;

using mint = hl::ModInt<1000000007>;

int main(){
  int N, K; std::cin >> N >> K;

  auto p = hl::partition_number<mint>(N, K);

  std::cout << p[N][K] << std::endl;

  return 0;
}
