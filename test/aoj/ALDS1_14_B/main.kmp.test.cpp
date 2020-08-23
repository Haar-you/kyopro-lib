#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "Mylib/String/knuth_morris_pratt.cpp"

int main(){
  std::string t, p; std::cin >> t >> p;

  auto res = KMP(p).match(t);
  for(auto i : res) std::cout << i << "\n";
  
  return 0;
}
