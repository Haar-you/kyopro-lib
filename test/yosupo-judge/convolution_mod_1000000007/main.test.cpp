#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/IO/join.cpp"

const int mod = 1000000007;
using mint = ModInt<mod>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int n, m; std::cin >> n >> m;
  std::vector<int64_t> a(n), b(m);
  for(int i = 0; i < n; ++i) std::cin >> a[i];
  for(int i = 0; i < m; ++i) std::cin >> b[i];

  auto ans = ntt_convolution<mint>(a,b);

  std::cout << join(ans.begin(), ans.begin() + n + m - 1) << "\n";
  
  return 0;
}
