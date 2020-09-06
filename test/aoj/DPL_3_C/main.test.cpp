#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  int N; std::cin >> N;

  auto h = input_vector<int64_t>(N);

  auto ans = max_rectangle_in_histogram(h);

  std::cout << ans << std::endl;

  return 0;
}
