#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549"

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int N; std::cin >> N;

  auto a = hl::input_vector<uint32_t>(N);

  auto wm = hl::make_wavelet_matrix_int(a);

  int Q; std::cin >> Q;

  for(auto [l, r, d] : hl::input_tuples<uint32_t, uint32_t, uint32_t>(Q)){
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
