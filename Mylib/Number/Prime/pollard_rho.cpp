#pragma once
#include <algorithm>
#include <cassert>
#include <numeric>
#include <optional>
#include <utility>
#include <vector>
#include "Mylib/Misc/int128.cpp"
#include "Mylib/Number/Prime/miller_rabin.cpp"

namespace haar_lib {
  namespace pollard_rho_impl {
    int128_t f(int128_t x) {
      return x * x + 1;
    }

    std::optional<int64_t> rho(int64_t n) {
      int64_t x = 2, y = 2, d = 1;

      while (d == 1) {
        x = f(x) % n;
        y = f(f(y) % n) % n;
        d = std::gcd(std::abs(x - y), n);
        if (d == n) return {};
      }

      return {d};
    }
  }  // namespace pollard_rho_impl

  auto pollard_rho(int64_t n) -> std::vector<std::pair<int64_t, int64_t>> {
    std::vector<std::pair<int64_t, int64_t>> ret;

    for (int i = 2; i <= 1000000; ++i) {
      if (n % i == 0) {
        int c = 0;
        while (n % i == 0) {
          n /= i;
          ++c;
        }
        ret.emplace_back(i, c);
      }
      if (i > n) break;
    }

    while (n > 1) {
      if (miller_rabin(n)) {
        ret.emplace_back(n, 1);
        break;
      }

      auto res = pollard_rho_impl::rho(n);
      if (not res) {
        assert(false);
      }

      auto r = *res;
      if (r == 1) break;

      int c = 0;
      while (n % r == 0) {
        n /= r;
        ++c;
      }

      ret.emplace_back(r, c);
    }

    std::sort(ret.begin(), ret.end());

    return ret;
  }
}  // namespace haar_lib
