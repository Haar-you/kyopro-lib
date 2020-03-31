#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/combinatorics.cpp"
#include "Mylib/Combinatorics/bell_number.cpp"

using C = Combinatorics<ModInt<1000000007>>;

int main(){
  C::init(3000);

  int N, K; std::cin >> N >> K;

  std::cout << C::bell_number(N, K) << std::endl;

  return 0;
}
