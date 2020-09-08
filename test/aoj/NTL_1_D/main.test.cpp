#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>
#include "Mylib/Number/Prime/count_coprime.cpp"

namespace hl = haar_lib;

int main(){
  int n; std::cin >> n;

  std::cout << hl::count_coprime(n, n) << std::endl;

  return 0;
}
