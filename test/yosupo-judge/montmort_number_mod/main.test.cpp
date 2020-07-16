#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include <iostream>
#include "Mylib/Number/Mint/runtime_mint.cpp"
#include "Mylib/Combinatorics/montmort_number.cpp"
#include "Mylib/IO/join.cpp"

struct tag{};
using mint = RuntimeModInt<tag>;

int main(){
  int N, M; std::cin >> N >> M;

  mint::M = M;

  auto ans = montmort_number<mint>(1000000);

  std::cout << join(ans.begin() + 1, ans.begin() + N + 1) << "\n";

  return 0;
}
