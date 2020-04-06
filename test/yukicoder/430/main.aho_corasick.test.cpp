#define PROBLEM "https://yukicoder.me/problems/no/430"

#include <iostream>
#include <string>
#include <vector>

#include "Mylib/String/aho_corasick.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  std::string S; std::cin >> S;
  int M; std::cin >> M;

  std::vector<std::string> C(M);
  for(int i = 0; i < M; ++i) std::cin >> C[i];

  AhoCorasick ac;
  for(int i = 0; i < M; ++i){
    ac.add(C[i]);
  }

  ac.build();
  
  int ans = 0;
  ac.match(S, [&](int, int){++ans;});
  
  std::cout << ans << std::endl;
  
  return 0;
}
