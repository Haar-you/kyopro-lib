#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include <iostream>
#include "Mylib/Number/Mint/runtime_mint.cpp"
#include "Mylib/Combinatorics/montmort_number.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

struct tag {};
using mint = hl::runtime_modint<tag>;

int main(){
  int N, M; std::cin >> N >> M;

  mint::init(M);

  auto ans = hl::montmort_number<mint>(1000000);

  std::cout << hl::join(ans.begin() + 1, ans.begin() + N + 1) << "\n";

  return 0;
}
