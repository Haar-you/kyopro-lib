#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <iostream>
#include <string>
#include "Mylib/String/suffix_array.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string S;

  while(std::cin >> S){
    SuffixArray<std::string> sa(S);

    std::cout << join(sa.begin() + 1, sa.end()) << "\n";
  }

  return 0;
}
