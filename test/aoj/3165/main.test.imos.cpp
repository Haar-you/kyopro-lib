#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165"

#include <iostream>
#include "Mylib/Algorithm/Imos/linear_imos_1d.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto imos = hl::linear_imos_1d<int64_t>(N);

  for(auto [l, k] : hl::input_tuples<int, int>(Q)){
    --l;
    imos.update(l, l + k, 1, 1);
  }

  const auto res = imos.build();

  std::cout << hl::join(res.begin(), res.end()) << "\n";

  return 0;
}
