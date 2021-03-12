#pragma once
#include <limits>
#include <type_traits>
#include <cstdint>

namespace haar_lib {
  constexpr bool has_single_bit(uint64_t x){
    return x != 0 and (x & (x - 1)) == 0;
  }

  constexpr int countl_zero(uint64_t x){
    if(x == 0) return 64;
    return __builtin_clzll(x);
  }

  constexpr int countl_one(uint64_t x){
    return countl_zero(~x);
  }

  constexpr int countr_zero(uint64_t x){
    if(x == 0) return 64;
    return __builtin_ctzll(x);
  }

  constexpr int countr_one(uint64_t x){
    return countr_zero(~x);
  }

  constexpr uint64_t bit_width(uint64_t x){
    if(x == 0) return 0;
    return 64 - countl_zero(x);
  }

  constexpr uint64_t bit_ceil(uint64_t x){
    if(has_single_bit(x)) return x;
    return 1LL << bit_width(x);
  }

  constexpr uint64_t bit_floor(uint64_t x){
    if(has_single_bit(x)) return x;
    return bit_ceil(x) >> 1;
  }

  constexpr int popcount(uint64_t x){
    return __builtin_popcountll(x);
  }

  template <typename T>
  constexpr T rotl(T x, int s){
    static_assert(std::is_unsigned_v<T>, "T must be an unsigned integer type.");
    constexpr int N = std::numeric_limits<T>::digits;
    s %= N;
    if(s == 0) return x;
    else if(s > 0) return (x << s) | (x >> (N - s));
    else return (x >> -s) | (x << (N + s));
  }

  template <typename T>
  constexpr T rotr(T x, int s){
    return rotl(x, -s);
  }
}
