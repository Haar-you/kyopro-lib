#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <iostream>
#include "Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;
  std::vector<int64_t> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  auto c = CumulativeSum1D(a);
  c.build();

  while(Q--){
    int l, r; std::cin >> l >> r;
    std::cout << c.get(l, r) << "\n";
  }

  return 0;
}
