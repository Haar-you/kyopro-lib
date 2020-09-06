#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <iostream>
#include <vector>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Algorithm/Query/range_inversions_query.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;
  auto A = input_vector<int>(N);

  RangeInversionsQuery riq(A);

  for(auto [l, r] : input_tuples<int, int>(Q)){
    riq.add(l, r);
  }

  auto ans = riq.solve();

  for(auto x : ans){
    std::cout << x << "\n";
  }

  return 0;
}
