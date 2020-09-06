#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Number/tetration.cpp"

int main(){
  int T; std::cin >> T;

  for(auto [A, B, M] : input_tuples<int, int, int>(T)){
    auto ans = tetration(A, B, M);
    std::cout << ans << "\n";
  }

  return 0;
}
