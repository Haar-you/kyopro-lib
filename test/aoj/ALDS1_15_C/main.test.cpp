#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling.cpp"

int main(){
  int n; std::cin >> n;
  
  std::vector<int> left(n), right(n);
  for(int i = 0; i < n; ++i){
    int s,t; std::cin >> s >> t;
    left[i] = s;
    right[i] = t+1;
  }
  
  auto ans = interval_scheduling(left, right);
  
  std::cout << ans.size() << std::endl;
  
  return 0;
}
