#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=ja"

#include <iostream>
#include "Mylib/Number/Divisor/divisor_list.cpp"

int main(){
  int a, b, c; std::cin >> a >> b >> c;

  int ans = 0;

  for(auto d : divisor_list(c)){
    if(a <= d and d <= b) ++ans;
  }

  std::cout << ans << std::endl;

  return 0;
}
