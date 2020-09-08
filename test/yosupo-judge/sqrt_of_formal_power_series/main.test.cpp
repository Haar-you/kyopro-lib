#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include <iostream>
#include <vector>
#include <functional>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Number/Mod/mod_sqrt.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;
using FPS = hl::formal_power_series<mint>;
using NTT = hl::number_theoretic_transform<mint, 3, 1 << 21>;

int main(){
  using namespace std::placeholders;
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  auto ntt = NTT();
  FPS::convolve = std::bind(&NTT::convolve<mint>, &ntt, _1, _2);
  FPS::get_sqrt = [&](const auto &a){return hl::mod_sqrt((int64_t)a, mint::MOD);};

  int N; std::cin >> N;
  auto a = hl::input_vector<mint>(N);
  auto ans = FPS(a).sqrt();

  if(ans){
    std::cout << hl::join((*ans).begin(), (*ans).begin() + N) << "\n";
  }else{
    std::cout << -1 << "\n";
  }

  return 0;
}
