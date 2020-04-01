#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C"

#include <iostream>
#include <string>
#include <vector>
#include "Mylib/String/rolling_hash_2d.cpp"


using RH = RollingHash2D<std::vector<std::string>, 30, 40, 1000000007>;

int main(){
  RH::init(1000, 1000);
  
  int H, W; std::cin >> H >> W;
  std::vector<std::string> s(H);
  for(int i = 0; i < H; ++i) std::cin >> s[i];

  int R, C; std::cin >> R >> C;
  std::vector<std::string> t(R);
  for(int i = 0; i < R; ++i) std::cin >> t[i];

  auto table = RH::gen_hash_table(s);
  auto hash = RH::gen_hash(t);
  
  for(int i = 0; i <= H-R; ++i){
    for(int j = 0; j <= W-C; ++j){
      if(table.get(i, j, i + R, j + C) == hash){
        std::cout << i << " " << j << std::endl;
      }
    }
  }


  return 0;
}
