#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

const int mod = 1000000007;
using mint = ModInt<mod>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int n, m; std::cin >> n >> m;

  auto a = input_vector<int64_t>(n);
  auto b = input_vector<int64_t>(m);

  auto ans = convolve_general_mod<mint>(a, b);

  std::cout << join(ans.begin(), ans.begin() + n + m - 1) << "\n";
  
  return 0;
}
