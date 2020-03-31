#pragma once

int count_divisor(std::int64_t n){
  int count = 0;
  for(std::int64_t i = 1LL; i * i <= n; ++i){
    if(n % i == 0){
      count += 2;
      if(i * i == n) count -= 1;
    }
  }
  return count;
}
