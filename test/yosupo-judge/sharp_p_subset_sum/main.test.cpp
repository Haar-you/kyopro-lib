#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include <iostream>
#include <functional>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/Typical/SubsetSumProblem/subset_sum_count_fps.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;
using NTT = hl::number_theoretic_transform<mint, 3, 1 << 21>;
const static auto ntt = NTT();
using FPS = hl::formal_power_series<mint, ntt>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, T; std::cin >> N >> T;
  auto s = hl::input_vector<int>(N);

  auto ans = hl::subset_sum_count_fps<FPS>(s, T);

  std::cout << hl::join(ans.begin() + 1, ans.begin() + T + 1) << "\n";

  return 0;
}

