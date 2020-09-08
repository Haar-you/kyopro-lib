#pragma once
#include <tuple>

/**
 * @title Extended Euclidean algorithm
 * @docs extended_gcd.md
 */
namespace haar_lib {
  std::tuple<int64_t, int64_t, int64_t> ext_gcd(int64_t a, int64_t b){
    if(b == 0) return std::make_tuple(a, 1, 0);
    int64_t d, p, q;
    std::tie(d, q, p) = ext_gcd(b, (a + b) % b);
    return std::make_tuple(d, p, q - a / b * p);
  }
}
