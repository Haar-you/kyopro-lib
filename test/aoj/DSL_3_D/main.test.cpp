#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <iostream>
#include <vector>
#include "Mylib/Algorithm/SlidingWindow/sliding_minimum.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  int N,L; std::cin >> N >> L;

  auto a = input_vector<int>(N);

  auto ans = sliding_minimum(a, L);

  std::cout << join(ans.begin(), ans.end()) << std::endl;

  return 0;
}
