#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"

#include <iostream>
#include "Mylib/Math/nim_product.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int T;
  std::cin >> T;

  while (T--) {
    uint64_t A, B;
    std::cin >> A >> B;
    std::cout << hl::nim_product_64(A, B) << "\n";
  }

  return 0;
}
