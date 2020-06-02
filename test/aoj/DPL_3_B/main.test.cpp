#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  int H, W; std::cin >> H >> W;

  auto c = input_vector<int>(H, W);
  
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      c[i][j] ^= 1;
    }
  }
  
  auto ans = max_rectangle(c);
  std::cout << ans << std::endl;
  
  return 0;
}
