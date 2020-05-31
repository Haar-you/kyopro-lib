#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto a = input_vector<uint32_t>(N);

  auto wm = make_wavelet_matrix_int(a);

  for(auto [l, r, k] : input_tuples<int, int, int>(Q)){
    auto ans = *wm.quantile(l, r, k+1);
    std::cout << ans << "\n";
  }
  
  return 0;
}
