#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549"

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"

int main(){
  int N; std::cin >> N;

  std::vector<uint32_t> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  auto wm = make_wavelet_matrix_int(a);
  
  int Q; std::cin >> Q;

  while(Q--){
    uint32_t l, r, d; std::cin >> l >> r >> d;

    ++r;

    int ans = INT_MAX;

    {
      auto x = wm.prev_value(l, r, d);
      if(x) ans = std::min(ans, std::abs((int)*x - (int)d));
    }

    {
      auto x = wm.next_value(l, r, d);
      if(x) ans = std::min(ans, std::abs((int)*x - (int)d));
    }

    std::cout << ans << std::endl;
  }

  return 0;
}
