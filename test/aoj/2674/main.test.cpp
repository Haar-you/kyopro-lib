#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674"

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/DataStructure/WaveletMatrix/range_freq.cpp"

int main(){
  int D; std::cin >> D;

  std::vector<uint32_t> x(D);
  for(int i = 0; i < D; ++i){
    std::cin >> x[i];
    x[i] += 100000000;
  }

  auto wm = make_wavelet_matrix_int(x);

  int Q; std::cin >> Q;

  while(Q--){
    int l, r, e; std::cin >> l >> r >> e;

    --l, --r;

    int a = std::min(x[l], x[r]);
    int b = std::max(x[l], x[r]);

    int ans = 0;

    ans += range_freq(wm, l, r+1, 0u, (uint32_t)std::max(0, a-e));
    ans += range_freq(wm, l, r+1, (uint32_t)(b+e+1), std::numeric_limits<uint32_t>::max());

    std::cout << ans << std::endl;
  }

  return 0;
}
