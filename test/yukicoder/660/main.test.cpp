#define PROBLEM "https://yukicoder.me/problems/no/660"

#include <iostream>
#include <vector>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Combinatorics/catalan_number.cpp"

using mint = ModInt<1000000007>;
using Ft = FactorialTable<mint>;

int main(){
  Ft::init(500000);
  
  int N; std::cin >> N;

  std::vector<mint> c(N+1);
  for(int i = 0; i <= N; ++i){
    c[i] = Ft::catalan_number(i);
  }

  for(int i = 1; i <= N; ++i){
    c[i] += c[i-1];
  }


  mint ans = 0;
  
  for(int k = 0; k <= N / 2; ++k){
    ans += Ft::C(N+2*k, k);
  }

  for(int k = 0; k < N / 2; ++k){
    ans -= Ft::C(N+2*k, k) * c[N/2-k-1] * 2;
  }

  std::cout << ans << std::endl;

  return 0;
}
