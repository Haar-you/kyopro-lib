#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include <iostream>
#include "Mylib/Number/Mint/runtime_mint.cpp"
#include "Mylib/Combinatorics/montmort_number.cpp"

using mint = RuntimeModInt;

int main(){
  int N, M; std::cin >> N >> M;

  mint::M = M;

  auto ans = montmort_number<mint>(1000000);

  for(int i = 1; i <= N; ++i){
    std::cout << ans[i] << " ";
  }

  return 0;
}
