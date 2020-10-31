#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include <iostream>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/subset_convolution.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;
  auto a = hl::input_vector<mint>(1 << N);
  auto b = hl::input_vector<mint>(1 << N);

  auto ans = hl::subset_convolution(a, b);

  std::cout << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}
