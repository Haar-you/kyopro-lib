#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Number/Mint/mint.cpp"

const int mod = 1000000007;
using mint = ModInt<mod>;

int main(){
  int n, m; scanf("%d%d", &n, &m);
  std::vector<int64_t> a(n), b(m);
  for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);
  for(int i = 0; i < m; ++i) scanf("%lld", &b[i]);

  auto ans = ntt_convolution<mint>(a,b);

  for(int i = 0; i < n+m-1; ++i){
    printf("%lld ", ans[i].val);
  }

  printf("\n");
  
  return 0;
}
