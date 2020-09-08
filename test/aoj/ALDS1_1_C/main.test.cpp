#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <iostream>
#include "Mylib/Number/Prime/is_prime.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int N; std::cin >> N;

  int ans = 0;

  for(auto [x] : hl::input_tuples<int>(N)) if(hl::is_prime(x)) ++ans;

  std::cout << ans << std::endl;

  return 0;
}
