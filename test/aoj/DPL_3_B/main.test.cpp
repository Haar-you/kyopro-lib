#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  int H, W; std::cin >> H >> W;

  auto c = input_vector<int>(H, W);

  auto ans = max_rectangle(c, 0);
  std::cout << ans << std::endl;

  return 0;
}
