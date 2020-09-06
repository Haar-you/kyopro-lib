#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"

#include <iostream>
#include <string>
#include "Mylib/String/run_enumerate.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s; std::cin >> s;

  auto ans = run_enumerate(s);

  std::cout << ans.size() << "\n";

  for(auto &[t, l, r] : ans){
    std::cout << t << " " << l << " " << r << "\n";
  }

  return 0;
}
