#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3119"

#include <iostream>
#include <vector>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/fast_zeta_transform_superset.cpp"
#include "Mylib/Convolution/fast_mobius_transform_superset.cpp"
#include "Mylib/IO/input_vector.cpp"

using mint = ModInt<1000000007>;

int main(){
  int n; std::cin >> n;

  auto a = input_vector<int>(n);

  std::vector<int> dp(1<<20);
  for(auto x : a) dp[x] += 1;

  dp = fast_zeta_transform_superset(dp);

  std::vector<mint> f(1<<20);
  for(int i = 0; i < 1<<20; ++i) f[i] = mint::power(2, dp[i]) - 1;

  auto ans = fast_mobius_transform_superset(f);

  std::cout << ans[0] << std::endl;
  
  return 0;
}
