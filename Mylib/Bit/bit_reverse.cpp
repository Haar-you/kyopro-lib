#pragma once
#include <cstdint>

/**
 * @title Bit reverse
 * @docs bit_reverse.md
 */
namespace haar_lib {
  int32_t bit_reverse(int32_t a){
    a = ((a & 0x55555555) << 1) | ((a & 0xaaaaaaaa) >> 1);
    a = ((a & 0x33333333) << 2) | ((a & 0xcccccccc) >> 2);
    a = ((a & 0x0f0f0f0f) << 4) | ((a & 0xf0f0f0f0) >> 4);
    a = ((a & 0x00ff00ff) << 8) | ((a & 0xff00ff00) >> 8);
    a = (a << 16) | (a >> 16);
    return a;
  }

  int64_t bit_reverse_ll(int64_t a){
    a = ((a & 0x5555555555555555) << 1) | ((a & 0xaaaaaaaaaaaaaaaa) >> 1);
    a = ((a & 0x3333333333333333) << 2) | ((a & 0xcccccccccccccccc) >> 2);
    a = ((a & 0x0f0f0f0f0f0f0f0f) << 4) | ((a & 0xf0f0f0f0f0f0f0f0) >> 4);
    a = ((a & 0x00ff00ff00ff00ff) << 8) | ((a & 0xff00ff00ff00ff00) >> 8);
    a = ((a & 0x0000ffff0000ffff) << 16) | ((a & 0xffff0000ffff0000) >> 16);
    a = (a << 32) | (a >> 32);
    return a;
  }
}
