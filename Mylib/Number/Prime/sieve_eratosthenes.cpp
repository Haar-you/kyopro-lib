#pragma once
#include <vector>

namespace haar_lib {
  class eratosthenes_sieve {
    std::vector<bool> is_prime_;

  public:
    eratosthenes_sieve() {}
    eratosthenes_sieve(int MAX) : is_prime_((MAX + 1) / 2, true) {
      is_prime_[0] = false;

      for (int i = 3; i * i <= MAX; i += 2) {
        if (not is_prime_[i / 2]) continue;

        for (int j = i * i; j <= MAX; j += 2 * i) {
          is_prime_[j / 2] = false;
        }
      }
    }

    bool operator()(int i) const {
      if (i == 2) return true;
      if (i % 2 == 0) return false;
      return is_prime_[i / 2];
    }
  };
}  // namespace haar_lib
