#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/Utils/sort_simultaneously.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

const int H = 1000000000;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m; std::cin >> n >> m;

  auto [x, y] = hl::input_tuple_vector<int, int>(n);

  hl::sort_simultaneously(
    [&](int i, int j){
      return x[i] < x[j];
    },
    x, y
  );

  for(auto &p : y) p += H;

  auto wm = hl::make_wavelet_matrix_int(std::vector<uint32_t>(y.begin(), y.end()));

  for(auto [x1, y1, x2, y2] : hl::input_tuples<int, int, int, int>(m)){
    const int l = std::lower_bound(x.begin(), x.end(), x1) - x.begin();
    const int r = std::upper_bound(x.begin(), x.end(), x2) - x.begin();
    int ans = wm.range_freq(l, r, y1 + H, y2 + H + 1);

    std::cout << ans << "\n";
  }

  return 0;
}
