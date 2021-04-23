#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  auto a = hl::input_vector<uint32_t>(N);

  auto wm = hl::make_wavelet_matrix_int(a);

  for (auto [l, r, k] : hl::input_tuples<int, int, int>(Q)) {
    auto ans = *wm.quantile(l, r, k + 1);
    std::cout << ans << "\n";
  }

  return 0;
}
