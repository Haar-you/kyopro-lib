#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
#include "Mylib/Number/Prime/miller_rabin.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  while(N--){
    int64_t x; std::cin >> x;
    std::cout << x << " " << MillerRabin::is_prime(x) << "\n";
  }

  return 0;
}
