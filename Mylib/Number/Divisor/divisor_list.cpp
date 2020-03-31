#pragma once
#include <vector>
#include <algorithm>

std::vector<std::int64_t> divisor_list(std::int64_t n){
  std::vector<std::int64_t> temp, ret;

  {
    std::int64_t i;
    for(i = 1LL; i * i < n; ++i){
      if(n%i == 0){
        temp.push_back(n / i);
        ret.push_back(i);
      }
    }
    if(i * i == n) ret.push_back(i);
  }

  std::reverse(temp.begin(), temp.end());
  ret.insert(ret.end(), temp.begin(), temp.end());
  
  return ret;
}
