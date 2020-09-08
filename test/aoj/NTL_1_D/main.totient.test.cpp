#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>
#include "Mylib/Number/euler_phi_function.cpp"

namespace hl = haar_lib;

int main(){
  int n; std::cin >> n;

  std::cout << hl::totient(n) << std::endl;

  return 0;
}
