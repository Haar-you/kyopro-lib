#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/partition_number_n.cpp"

using mint = ModInt<998244353>;

int main(){
  int N; std::cin >> N;

  auto p = partition_number<mint>(N);

  for(int i = 0; i <= N; ++i){
    std::cout << p[i] << " ";
  }

  return 0;
}
