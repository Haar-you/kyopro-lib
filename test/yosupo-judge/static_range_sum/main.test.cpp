#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <iostream>
#include "Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto a = input_vector<int64_t>(N);

  auto c = CumulativeSum1D(a).build();

  for(auto [l, r] : input_tuples<int, int>(Q)){
    std::cout << c.get(l, r) << "\n";
  }

  return 0;
}
