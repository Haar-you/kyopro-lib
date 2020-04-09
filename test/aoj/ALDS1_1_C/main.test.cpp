#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <iostream>
#include "Mylib/Number/Prime/is_prime.cpp"

int main(){
  int N; std::cin >> N;

  int ans = 0;
  
  while(N--){
    int x; std::cin >> x;
    if(is_prime(x)) ++ans;
  }

  std::cout << ans << std::endl;

  return 0;
}
