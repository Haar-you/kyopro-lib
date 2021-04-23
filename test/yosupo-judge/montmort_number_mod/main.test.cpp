#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include <iostream>
#include "Mylib/Combinatorics/montmort_number.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Mint/runtime_mint.cpp"

namespace hl = haar_lib;

static int M;
using mint = hl::runtime_modint<M>;

int main() {
  int N;
  std::cin >> N >> M;

  auto ans = hl::montmort_number<mint>(1000000);

  std::cout << hl::join(ans.begin() + 1, ans.begin() + N + 1) << "\n";

  return 0;
}
