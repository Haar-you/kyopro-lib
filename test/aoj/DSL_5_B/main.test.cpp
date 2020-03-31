#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include <iostream>
#include <algorithm>
#include "Mylib/Algorithm/Imos/imos_2d.cpp"

int main(){
  int N; std::cin >> N;
  Imos2D<int> imos(1000, 1000);

  for(int i = 0; i < N; ++i){
    int x1,y1,x2,y2; std::cin >> x1 >> y1 >> x2 >> y2;
    imos.add(x1,y1,x2,y2);
  }

  imos.build();

  int ans = 0;
  for(int i = 0; i < 1000; ++i){
    for(int j = 0; j < 1000; ++j){
      ans = std::max(ans, imos[i][j]);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
