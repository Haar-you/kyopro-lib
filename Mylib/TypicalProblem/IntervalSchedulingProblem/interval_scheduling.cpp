#pragma once
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>
#include <utility>

/**
 * @title Interval scheduling problem
 * @docs interval_scheduling.md
 */
template <typename T>
std::vector<std::pair<T, T>> interval_scheduling(const std::vector<T> &l, const std::vector<T> &r){
  const int N = l.size();
  std::vector<std::pair<T, T>> ret;
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j){return r[i] < r[j];});

  auto b = std::numeric_limits<T>::lowest();

  for(int i : ord){
    if(l[i] >= b){
      ret.emplace_back(l[i], r[i]);
      b = r[i];
    }
  }

  return ret;
}
