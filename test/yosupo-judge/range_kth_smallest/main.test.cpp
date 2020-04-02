#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"

int main(){
  
  int N, Q; scanf("%d%d", &N, &Q);

  std::vector<uint32_t> a(N);
  for(int i = 0; i < N; ++i) scanf("%d", &a[i]);

  auto wv = make_wavelet_matrix_int(a);

  while(Q--){
    int l, r, k; scanf("%d%d%d", &l, &r, &k);
    auto ans = wv.quantile(l, r, k+1);
    printf("%d\n", ans);
  }
  
  return 0;
}
