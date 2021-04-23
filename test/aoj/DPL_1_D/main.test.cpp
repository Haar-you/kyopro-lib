#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <iostream>
#include <vector>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Typical/longest_increasing_subsequence.cpp"

namespace hl = haar_lib;

int main() {
  int N;
  std::cin >> N;

  auto a = hl::input_vector<int>(N);

  auto ans = hl::longest_increasing_subsequence(a).size();
  std::cout << ans << std::endl;

  return 0;
}
