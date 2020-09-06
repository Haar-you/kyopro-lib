#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <iostream>
#include <vector>
#include "Mylib/DynamicProgramming/longest_increasing_subsequence.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  int N; std::cin >> N;

  auto a = input_vector<int>(N);

  auto ans = lis(a);
  std::cout << ans << std::endl;

  return 0;
}
