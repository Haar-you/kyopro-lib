#pragma once
#include <cassert>
#include <cstdint>
#include <vector>

namespace haar_lib {
  template <typename Checker>
  class segmented_sieve {
    int L_, R_, D_;
    std::vector<bool> data_;

  public:
    segmented_sieve() {}
    segmented_sieve(int l, int r, Checker is_prime) :  // [l, r]
                                                      L_(l),
                                                      R_(r),
                                                      D_(R_ - L_ + 1),
                                                      data_(D_, true) {
      std::vector<int> primes;
      for (int64_t i = 2; i * i <= R_; ++i) {
        if (is_prime(i)) primes.push_back(i);
      }

      for (int64_t i = 0; i < D_; ++i) {
        const int64_t x = L_ + i;

        if (x == 1) {
          data_[i] = false;
          continue;
        }

        for (auto p : primes) {
          if (x == p) break;
          if (x % p == 0) {
            data_[i] = false;
            break;
          }
        }
      }
    }

    bool operator()(int i) const {
      assert(L_ <= i and i <= R_);
      return data_[i - L_];
    }
  };
}  // namespace haar_lib
