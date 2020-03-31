#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549"

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/DataStructure/WaveletMatrix/prev_next_value.cpp"

int main(){
  int N; std::cin >> N;

  std::vector<uint32_t> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  auto wm = make_wavelet_matrix_int(a);
  
  int Q; std::cin >> Q;

  while(Q--){
    int l, r, d; std::cin >> l >> r >> d;

    ++r;

    int ans = INT_MAX;

    {
      int x = wm.prev_value(l, r, d);
      if(x != -1) ans = std::min(ans, std::abs(x - d));
    }

    {
      int x = wm.next_value(l, r, d);
      if(x != -1) ans = std::min(ans, std::abs(x - d));
    }


    std::cout << ans << std::endl;
  }

  return 0;
}
