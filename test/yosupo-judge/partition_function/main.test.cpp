#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/partition_number_n.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;

int main(){
  int N; std::cin >> N;

  auto p = hl::partition_number<mint>(N);

  std::cout << hl::join(p.begin(), p.end()) << std::endl;

  return 0;
}
