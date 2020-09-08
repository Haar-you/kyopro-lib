#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <iostream>
#include "Mylib/Number/Prime/prime_factorize.cpp"

namespace hl = haar_lib;

int main(){
  int n; std::cin >> n;

  auto res = hl::prime_factorize(n);

  std::cout << n << ":";

  for(auto &[x, c] : res){
    for(int i = 0; i < c; ++i){
      std::cout << " " << x;
    }
  }

  std::cout << std::endl;

  return 0;
}
