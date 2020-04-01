#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>
#include "Mylib/String/z_algorithm.cpp"


int main(){
  std::string s; std::cin >> s;
  
  auto ans = z_algorithm(s);
  for(auto &x : ans) std::cout << x << " ";

  return 0;
}
