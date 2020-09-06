#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "Mylib/String/rolling_hash.cpp"

int main(){
  auto rh = make_rh(1000000, 1000000007);

  std::string t, p; std::cin >> t >> p;

  auto res = rh.find(t, p);
  for(auto i : res) std::cout << i << "\n";

  return 0;
}
