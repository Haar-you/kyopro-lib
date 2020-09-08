#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include <iostream>
#include <string>
#include "Mylib/String/suffix_array.cpp"
#include "Mylib/String/lcp_array.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s; std::cin >> s;
  const int N = s.size();

  auto sa = hl::suffix_array(s);
  auto lcp = hl::lcp_array(sa);

  int64_t ans = 0;

  for(int i = 1; i <= N; ++i){
    ans += N - sa[i];
    ans -= lcp[i];
  }

  std::cout << ans << std::endl;

  return 0;
}
