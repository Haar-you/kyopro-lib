#define PROBLEM "https://yukicoder.me/problems/no/843"

#include <iostream>
#include "Mylib/Number/Prime/atkin_sieve.cpp"

using P = AtkinSieve<500000>;

int main(){
  P::init();
  
  int N; std::cin >> N;

  int64_t ans = 0;

  if(N >= 2){
    ans += 1;

    int t = 0;
    for(int64_t r = 3; r <= N; ++r){
      int64_t q = r * r - 2;
      if(q <= N and P::is_prime[r] and P::is_prime[q]) ++t;
    }

    ans += t * 2;
  }
  
  std::cout << ans << std::endl;

  return 0;
}
