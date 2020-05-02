#pragma once

/**
 * @title 床関数・天井関数
 * @docs floor_ceil.md
 */
int64_t ceil(int64_t a, int64_t b){
  if((a <= 0 and b < 0) or (a >= 0 and b > 0)) return (abs(a) + abs(b) - 1) / abs(b);
  return - (abs(a) / abs(b));
}

int64_t floor(int64_t a, int64_t b){
  if((a <= 0 and b < 0) or (a >= 0 and b > 0)) return a / b;
  return - (abs(a) + abs(b) - 1) / abs(b);
}
