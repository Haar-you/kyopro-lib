#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/partition_number_n.cpp"
#include "Mylib/IO/join.cpp"

using mint = ModInt<998244353>;

int main(){
  int N; std::cin >> N;

  auto p = partition_number<mint>(N);

  std::cout << join(p.begin(), p.end()) << std::endl;

  return 0;
}
