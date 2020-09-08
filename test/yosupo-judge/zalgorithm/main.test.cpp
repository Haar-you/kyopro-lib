#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>
#include "Mylib/String/z_algorithm.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

int main(){
  std::string s; std::cin >> s;

  auto ans = hl::z_algorithm(s);
  std::cout << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}
