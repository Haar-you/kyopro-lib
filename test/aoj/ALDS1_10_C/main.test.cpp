#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include <iostream>
#include <string>
#include "Mylib/DynamicProgramming/longest_common_subsequence.cpp"

int main(){
  int q; std::cin >> q;
  
  while(q--){
    std::string x, y; std::cin >> x >> y;
    
    auto ans = lcs(x, y);
    
    std::cout << ans << std::endl;
  }
  
  return 0;
}
