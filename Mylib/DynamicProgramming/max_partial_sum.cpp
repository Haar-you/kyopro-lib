#pragma once
#include <vector>
#include <algorithm>

/**
 * @title Maximum subarray problem
 * @docs max_partial_sum.md
 */
template <typename T>
T max_partial_sum(const std::vector<T> &v){
  T t = v[0], ret = t;
  for(int i = 1; i < (int)v.size(); ++i){
    t = std::max(t + v[i], v[i]);
    ret = std::max(ret, t);
  }
  return ret;
}
