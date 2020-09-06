#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C"

#include <iostream>
#include <string>
#include <vector>
#include "Mylib/String/rolling_hash_2d.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  auto rh = make_rh_2d(1000, 1000, 1000000007);

  int H, W; std::cin >> H >> W;
  auto s = input_vector<std::string>(H);

  int R, C; std::cin >> R >> C;
  auto t = input_vector<std::string>(R);

  auto res = rh.find(s, t);
  for(auto [i, j] : res) std::cout << i << " " << j << "\n";

  return 0;
}
