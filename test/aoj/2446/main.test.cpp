#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446"
#define ERROR 1e-7

#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include "Mylib/Convolution/fast_mobius_transform_subset.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int64_t n, m; std::cin >> n >> m;

  auto a = hl::input_vector<int64_t>(n);
  auto p = hl::input_vector<double>(n);

  for(auto &x : p) x /= 100.0;

  std::vector<int64_t> dp(1 << n);
  for(int i = 1; i < 1 << n; ++i){
    int64_t l = 1;
    for(int j = 0; j < n; ++j){
      if((i >> j) & 1){
        int64_t g = std::gcd(l, a[j]);

        long long int k;
        if(__builtin_smulll_overflow(l / g, a[j], &k)){
          l = m + 1;
          break;
        }
        l = (l / g) * a[j];
      }
    }
    dp[i] = m / l;
  }

  dp = hl::fast_mobius_transform_subset(dp);

  double ans = 0.0;

  for(int i = 0; i < (1 << n); ++i){
    double q = 1.0;
    for(int j = 0; j < n; ++j){
      if(i >> j & 1) q *= p[j];
      else q *= 1.0 - p[j];
    }
    ans += q * std::abs(dp[i]);
  }

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}
