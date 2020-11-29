#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <iostream>
#include <string>
#include "Mylib/String/manacher.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string S; std::cin >> S;

  auto ans = hl::manacher_all(S);
  std::cout << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}
