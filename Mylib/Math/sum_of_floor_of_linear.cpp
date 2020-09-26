#pragma once
#include <cstdint>

namespace haar_lib {
  int64_t sum_of_floor_of_linear(int64_t N, int64_t M, int64_t A, int64_t B){
    int64_t ret = 0;

    if(B >= M){
      ret += N * (B / M);
      B %= M;
    }

    if(A >= M){
      ret += N * (N - 1) * (A / M) / 2;
      A %= M;
    }

    int64_t y_max = (A * N + B) / M;
    int64_t x_max = y_max * M - B;
    if(y_max == 0) return ret;

    ret += (N - (x_max + A - 1) / A) * y_max;
    ret += sum_of_floor_of_linear(y_max, A, M, (A - x_max % A) % A);
    return ret;
  }
}
