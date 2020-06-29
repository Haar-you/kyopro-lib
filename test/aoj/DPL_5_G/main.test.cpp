#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Combinatorics/bell_number.cpp"

using Ft = FactorialTable<ModInt<1000000007>>;

int main(){
  Ft::init(3000);

  int N, K; std::cin >> N >> K;

  std::cout << Ft::bell_number(N, K) << std::endl;

  return 0;
}
