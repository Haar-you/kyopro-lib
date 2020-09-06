#pragma once
#include <cstdint>

/**
 * @title Xorshift
 * @docs xor_shift.md
 */
struct XorShift {
  static uint64_t rand(){
    static uint64_t x = 1234567889, y = 362436069, z = 521288629, w = 88675123;

    uint64_t t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    return w;
  }

  static uint64_t rand(uint64_t s, uint64_t t){ // [s, t)
    return s + rand() % (t - s);
  }
};
