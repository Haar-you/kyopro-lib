#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <iostream>
#include <vector>
#include "Mylib/Algorithm/SlidingWindow/sliding_minimum.cpp"

int main(){
  int N,L; std::cin >> N >> L;
  std::vector<int> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  auto ans = sliding_minimum(a, L);

  for(int i = 0; i < (int)ans.size(); ++i){
    if(i) std::cout << " ";
    std::cout << ans[i];
  }
  std::cout << std::endl;

  return 0;
}

