#pragma once
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>
#include <utility>

/**
 * @title 区間スケジューリング問題
 * @see https://atcoder.jp/contests/kupc2015/submissions/6604297
 * @see https://codeforces.com/contest/528/submission/57933292
 * @attention time complexity O(N log N)
 */
template <typename T>
std::vector<std::pair<T,T>> interval_scheduling(const std::vector<T> &left, const std::vector<T> &right){ // 区間は[a,b]
  const int N = left.size();
  std::vector<std::pair<T,T>> ret;
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j){return right[i] < right[j];});

  auto b = std::numeric_limits<T>::lowest();

  for(int i : ord){
    if(left[i] >= b){
      ret.emplace_back(left[i], right[i]);
      b = right[i];
    }
  }
  
  return ret;
}
