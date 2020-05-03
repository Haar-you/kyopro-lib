#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E"

#include <iostream>
#include <string>
#include "Mylib/DynamicProgramming/levenshtein_distance.cpp"

int main(){
  std::string s1, s2; std::cin >> s1 >> s2;
  
  auto ans = levenshtein_distance(s1, s2);
  
  std::cout << ans << std::endl;
  
  return 0;
}