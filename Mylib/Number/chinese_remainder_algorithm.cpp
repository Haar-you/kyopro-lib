#pragma once
#include <vector>
#include <optional>
#include "Mylib/Number/extended_gcd.cpp"

namespace haar_lib {
  std::optional<std::pair<int64_t, int64_t>> chinese_remainder_algorithm(
    int64_t b1, int64_t m1,
    int64_t b2, int64_t m2
  ){
    const auto [d, p, q] = ext_gcd(m1, m2);
    if((b2 - b1) % d != 0) return std::nullopt;
    const int64_t m = m1 * m2 / d;
    const int64_t t = ((b2 - b1) * p / d) % (m2 / d);
    const int64_t r = (b1 + m1 * t + m) % m;
    return {{r, m}};
  }

  std::optional<std::pair<int64_t, int64_t>> chinese_remainder_algorithm(
    const std::vector<int64_t> &bs,
    const std::vector<int64_t> &ms
  ){
    int64_t R = 0, M = 1;
    for(int i = 0; i < (int)bs.size(); ++i){
      const auto res = chinese_remainder_algorithm(R, M, bs[i], ms[i]);
      if(not res) return std::nullopt;
      const auto [r, m] = *res;
      R = r;
      M = m;
    }
    return {{R, M}};
  }
}
