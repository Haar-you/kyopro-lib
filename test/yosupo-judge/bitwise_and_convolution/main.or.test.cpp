#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include <iostream>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/convolution_or.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

constexpr int mod = 998244353;
using mint = hl::modint<mod>;

auto index_bit_inverse(std::vector<mint> a){
  const int N = a.size();

  std::vector<mint> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = a[i ^ (N - 1)];

  return ret;
}

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;
  const auto a = index_bit_inverse(hl::input_vector<mint>(1 << N));
  const auto b = index_bit_inverse(hl::input_vector<mint>(1 << N));

  const auto ans = index_bit_inverse(convolution_or(a, b));
  std::cout << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}
