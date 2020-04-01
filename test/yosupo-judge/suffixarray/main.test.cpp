#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <iostream>
#include <string>
#include "Mylib/String/suffix_array.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  std::string S;

  while(std::cin >> S){
    SuffixArray<std::string> sa(S);

    for(auto x : sa.suffix_array){
      std::cout << x << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
