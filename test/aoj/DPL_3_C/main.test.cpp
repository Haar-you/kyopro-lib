#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"
     
#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp"
     
int main(){
  int N; std::cin >> N;
  
  std::vector<int64_t> h(N);
  for(int i = 0; i < N; ++i) std::cin >> h[i];
  
  auto ans = max_rectangle_in_histogram(h);
  
  std::cout << ans << std::endl;
  
  return 0;
}
