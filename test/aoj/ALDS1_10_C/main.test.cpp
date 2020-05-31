#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include <iostream>
#include <string>
#include "Mylib/String/longest_common_subsequence.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int q; std::cin >> q;
  
  for(auto [x, y] : input_tuples<std::string, std::string>(q)){
    std::cout << lcs(x, y) << std::endl;
  }
  
  return 0;
}
