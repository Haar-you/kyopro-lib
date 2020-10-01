#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A"

#include <iostream>
#include <algorithm>
#include "Mylib/Algorithm/Imos/imos_1d.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int N, T; std::cin >> N >> T;
  hl::imos_1d<int> imos(T + 1);

  for(auto [l, r] : hl::input_tuples<int, int>(N)){
    imos.update(l, r, 1);
  }

  imos.build();

  int ans = *std::max_element(imos.begin(), imos.end());

  std::cout << ans << std::endl;

  return 0;
}
