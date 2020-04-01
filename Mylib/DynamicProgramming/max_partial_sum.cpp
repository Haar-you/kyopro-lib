#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 連続部分和の最大値
 */
template <typename T>
T max_partial_sum(const std::vector<T> &v){
  T t = v[0], ret = t;
  for(int i = 1; i < (int)v.size(); ++i){
    t = std::max(t+v[i], v[i]);
    ret = std::max(ret, t);
  }
  return ret;
}
