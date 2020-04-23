#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C"

#include <iostream>
#include <string>
#include <vector>
#include "Mylib/String/rolling_hash_2d.cpp"

int main(){
  auto rh = make_rh_2d(1000, 1000, 1000000007);
  
  int H, W; std::cin >> H >> W;
  std::vector<std::string> s(H);
  for(int i = 0; i < H; ++i) std::cin >> s[i];

  int R, C; std::cin >> R >> C;
  std::vector<std::string> t(R);
  for(int i = 0; i < R; ++i) std::cin >> t[i];

  auto table = rh.gen_hash_table(s);
  auto hash = rh.gen_hash(t);
  
  for(int i = 0; i <= H-R; ++i){
    for(int j = 0; j <= W-C; ++j){
      if(rh.get(table, i, j, i + R, j + C) == hash){
        std::cout << i << " " << j << std::endl;
      }
    }
  }

  return 0;
}
