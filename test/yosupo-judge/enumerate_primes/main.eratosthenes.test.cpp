#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <iostream>
#include <vector>
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Prime/sieve_eratosthenes.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, A, B;
  std::cin >> N >> A >> B;

  const auto is_prime = hl::eratosthenes_sieve(N);

  int pi = 0;
  std::vector<int> ans;

  for (int i = 2; i <= N; ++i) {
    if (is_prime(i)) {
      if ((pi - B) % A == 0) {
        ans.push_back(i);
      }
      ++pi;
    }
  }

  std::cout << pi << " " << ans.size() << "\n"
            << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}
