#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A"

#include <iostream>
#include <algorithm>
#include "Mylib/Algorithm/Imos/imos_1d.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int N, T; std::cin >> N >> T;
  Imos1D<int> imos(T + 1);

  for(auto [l, r] : input_tuples<int, int>(N)){
    imos.add(l, r, 1);
  }

  imos.build();

  int ans = 0;

  for(int i = 0; i <= T; ++i){
    ans = std::max(ans, imos[i]);
  }

  std::cout << ans << std::endl;

  return 0;
}
