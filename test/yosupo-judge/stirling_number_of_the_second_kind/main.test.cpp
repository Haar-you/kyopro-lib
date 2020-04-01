#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"

const int MOD = 998244353;
const int PRIM = 3;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  
  int N; std::cin >> N;

  std::vector<int64_t> a(N+1), b(N+1);

  int64_t f = 1;
  
  for(int i = 0; i <= N; ++i){
    if(i) (f *= i) %= MOD;

    a[i] = power(i, N, MOD) * mod_inv(f, MOD) % MOD;
    b[i] = mod_inv(f, MOD);

    if(i % 2 == 1){
      b[i] = (MOD - b[i]) % MOD;
    }
  }

  auto res = NumberTheoreticTransform<MOD,PRIM,1<<20>().run_convolution(a, b);

  for(int i = 0; i <= N; ++i){
    std::cout << res[i] << " ";
  }
  std::cout << std::endl;
  
  return 0;
}
