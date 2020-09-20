#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include <iostream>
#include <tuple>
#include <functional>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Algorithm/CartesianTree/cartesian_tree.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;
  auto a = hl::input_vector<int>(N);

  auto ans = std::get<1>(hl::cartesian_tree(a, std::less<>()));

  for(int i = 0; i < N; ++i){
    std::cout << ans[i].value_or(i) << "\n";
  }

  return 0;
}
