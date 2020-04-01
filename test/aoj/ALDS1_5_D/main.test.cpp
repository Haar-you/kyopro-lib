#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include <iostream>
#include <vector>
#include <functional>
#include "Mylib/Misc/inverse_number.cpp"

int main(){
  int n; std::cin >> n;
  std::vector<int> a(n);
  for(int i = 0; i < n; ++i) std::cin >> a[i];
  
  auto ans = inverse_number::solve(a, std::greater<int>());
  std::cout << ans << std::endl;
  
  return 0;
}
