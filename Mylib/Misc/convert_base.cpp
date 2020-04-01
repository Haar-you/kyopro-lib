#pragma once
#include <vector>

std::vector<int64_t> convert_base_to(int64_t val, int64_t base){
  if(val == 0) return {0};

  std::vector<int64_t> ret;
  while(val){
    if(val < base){
      ret.push_back(val);
      break;
    }
    ret.push_back(val % base);
    val /= base;
  }
 
  return ret;
}

int64_t convert_base_from(const std::vector<int64_t> &val, int64_t base){
  int64_t ret = 0;
  for(auto it = val.rbegin(); it != val.rend(); ++it){
    (ret *= base) += *it;
  }

  return ret;
}
