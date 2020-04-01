#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <iostream>
#include <vector>
#include "Mylib/DynamicProgramming/longest_increasing_subsequence.cpp"

int main(){
  int N; std::cin >> N;
  std::vector<int> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];
  
  auto ans = lis(a);
  std::cout << ans << std::endl;
  
  return 0;
}
