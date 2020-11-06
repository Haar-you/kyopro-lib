#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include <iostream>
#include <vector>
#include "Mylib/Typical/max_rectangle_in_histogram.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

int main(){
  int N; std::cin >> N;

  auto h = hl::input_vector<int64_t>(N);

  auto ans = hl::max_rectangle_in_histogram(h);

  std::cout << ans << std::endl;

  return 0;
}
