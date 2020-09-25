#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>
#include "Mylib/Number/euler_totient_function.cpp"

namespace hl = haar_lib;

int main(){
  int n; std::cin >> n;

  std::cout << hl::totient(n) << std::endl;

  return 0;
}
