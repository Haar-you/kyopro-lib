#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674"

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

    ans += wm.range_freq(l, r+1, 0, std::max(0, a-e));
    ans += wm.range_freq(l, r+1, b+e+1, INT_MAX);

    std::cout << ans << std::endl;
  }

  return 0;
}
