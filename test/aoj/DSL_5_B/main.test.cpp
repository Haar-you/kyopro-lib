#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include <iostream>
#include <algorithm>
#include "Mylib/Algorithm/Imos/imos_2d.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int N; std::cin >> N;
  hl::imos_2d<int> imos(1000, 1000);

  for(auto [x1, y1, x2, y2] : hl::input_tuples<int, int, int, int>(N)){
    imos.update({x1, y1}, {x2, y2}, 1);
  }

  const auto res = imos.build();

  int ans = 0;
  for(auto &v : res){
    ans = std::max(ans, *std::max_element(v.begin(), v.end()));
  }

  std::cout << ans << std::endl;

  return 0;
}
