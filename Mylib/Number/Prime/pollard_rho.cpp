#pragma once
#include <optional>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <cassert>
#include "Mylib/Misc/int128.cpp"
#include "Mylib/Number/Prime/miller_rabin.cpp"

/**
 * @title Prime factorization (Pollard's rho algorithm)
 * @docs pollard_rho.md
 */
namespace pollard_rho_impl {
  int128_t f(int128_t x){
    return x * x + 1;
  }

  std::optional<int64_t> rho(int64_t n){
    int64_t x = 2, y = 2, d = 1;

    while(d == 1){
      x = f(x) % n;
      y = f(f(y) % n) % n;
      d = std::gcd(std::abs(x - y), n);
      if(d == n) return {};
    }

    return {d};
  }
}

auto pollard_rho(int64_t n){
  std::vector<std::pair<int64_t,int64_t>> ret;

  for(int i = 2; i <= 1000000; ++i){
    if(n % i == 0){
      int c = 0;
      while(n % i == 0){
        n /= i;
        ++c;
      }
      ret.emplace_back(i, c);
    }
    if(i > n) break;
  }

  MillerRabin is_prime;

  while(n > 1){
    if(is_prime(n)){
      ret.emplace_back(n, 1);
      break;
    }

    auto res = pollard_rho_impl::rho(n);
    if(not res){
      assert(false);
    }

    auto r = *res;
    if(r == 1) break;

    int c = 0;
    while(n % r == 0){
      n /= r;
      ++c;
    }

    ret.emplace_back(r, c);
  }

  std::sort(ret.begin(), ret.end());

  return ret;
}
