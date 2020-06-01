#pragma once
#include <vector>
#include <deque>
#include <utility>

/**
 * @title Sliding window minmax
 * @docs sliding_minmax.md
 */
template <typename T> std::vector<std::pair<T,T>> sliding_minmax(const std::vector<T> &a, int k){
  int n = a.size();
  std::deque<int> dq_min, dq_max;
  std::vector<std::pair<T,T>> ret;

  for(int i = 0; i < k; ++i){
    while(not dq_min.empty() and a[dq_min.back()] >= a[i]){
      dq_min.pop_back();
    }
    
    dq_min.push_back(i);

    while(not dq_max.empty() and a[dq_max.back()] <= a[i]){
      dq_max.pop_back();
    }
    
    dq_max.push_back(i);
  }

  for(int i = 0; i < n-k+1; ++i){
    while(dq_min.front() < i){
      dq_min.pop_front();
    }

    while(dq_max.front() < i){
      dq_max.pop_front();
    }

    ret.push_back(std::make_pair(a[dq_min.front()], a[dq_max.front()]));

    while(not dq_min.empty() and i+k < n and a[dq_min.back()] >= a[i+k]){
      dq_min.pop_back();
    }

    while(not dq_max.empty() and i+k < n and a[dq_max.back()] <= a[i+k]){
      dq_max.pop_back();
    }
    
    dq_min.push_back(i+k);
    dq_max.push_back(i+k);
  }
  
  return ret;
}
