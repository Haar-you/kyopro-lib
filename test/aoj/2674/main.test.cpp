#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674"

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int D; std::cin >> D;

  auto x = input_vector<uint32_t>(D);
  for(auto &v : x) v += 100000000;

  auto wm = make_wavelet_matrix_int(x);

  int Q; std::cin >> Q;

  for(auto [l, r, e] : input_tuples<int, int, int>(Q)){
    --l, --r;

    int a = std::min(x[l], x[r]);
    int b = std::max(x[l], x[r]);

    int ans = 0;

    ans += wm.range_freq(l, r + 1, 0u, (uint32_t)std::max(0, a - e));
    ans += wm.range_freq(l, r + 1, (uint32_t)(b + e + 1), std::numeric_limits<uint32_t>::max());

    std::cout << ans << std::endl;
  }

  return 0;
}
