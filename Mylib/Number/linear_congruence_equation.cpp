#pragma once
#include <optional>
#include <numeric>
#include "Mylib/Number/Mod/mod_inv.cpp"

namespace haar_lib {
  // ax + b = 0 (mod m)
  std::optional<int64_t> linear_congruence_equation(int64_t a, int64_t b, int64_t m){
    if(a >= m) a %= m;
    if(b >= m) b %= m;
    if(a < 0) (a += m) %= m;
    if(b < 0) (b += m) %= m;

    auto g = std::gcd(a, m);
    if(b % g == 0){
      a /= g;
      b /= g;
      m /= g;
    }

    if(std::gcd(a, m) == 1){
      return (m - b) * mod_inv(a, m) % m;
    }

    return std::nullopt;
  }
}
