#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include <iostream>
#include <string>

#include "Mylib/String/suffix_array.cpp"
#include "Mylib/String/lcp_array.cpp"


int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  std::string s; std::cin >> s;
  const int N = s.size();

  SuffixArray sa(s);
  LCPArray lcp(sa);

  int64_t ans = 0;

  for(int i = 0; i < N; ++i){
    ans += N - sa.suffix_array[i];

    if(i){
      ans -= lcp.lcp_array[i-1];
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
