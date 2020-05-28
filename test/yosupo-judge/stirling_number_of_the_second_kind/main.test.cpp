#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/IO/join.cpp"

const int MOD = 998244353;
const int PRIM = 3;

using mint = ModInt<MOD>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  std::vector<mint> a(N+1), b(N+1);

  std::vector<int> m(N+1, 0);
  for(int i = 2; i <= N; ++i){
    if(m[i] != 0) continue;
    for(int j = 2*i; j <= N; j += i){
      m[j] = i;
    }
  }

  for(int i = 0; i <= N; ++i){
    if(m[i] == 0){
      a[i] = mint::power(i, N);
    }else{
      a[i] = a[m[i]] * a[i/m[i]];
    }
  }
    
  mint f = 1;
  for(int i = 1; i <= N; ++i) f *= i;
  f = f.inv();

  for(int i = N; i >= 0; --i){
    a[i] *= f;
    b[i] = f;
    f *= i;

    if(i % 2 == 1){
      b[i] = -b[i];
    }
  }
  
  auto res = NumberTheoreticTransform<mint,PRIM,1<<20>().run_convolution(a, b);

  std::cout << join(res.begin(), res.begin() + N + 1) << "\n";
  
  return 0;
}
