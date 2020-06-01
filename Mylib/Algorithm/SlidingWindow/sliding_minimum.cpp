#pragma once
#include <vector>
#include <deque>

/**
 * @title Sliding window minimum
 * @docs sliding_minimum.md
 */
template <typename T>
std::vector<T> sliding_minimum(const std::vector<T> &a, int k){
  const int n = a.size();
  std::deque<int> dq;
  std::vector<T> ret;

  for(int i = 0; i < k; ++i){
    while(not dq.empty() and a[dq.back()] >= a[i]){
      dq.pop_back();
    }

    dq.push_back(i);
  }
  
  for(int i = 0; i < n-k+1; ++i){
    while(dq.front() < i){
      dq.pop_front();
    }

    ret.push_back(a[dq.front()]);

    while(not dq.empty() and i+k < n and a[dq.back()] >= a[i+k]){
      dq.pop_back();
    }
    
    dq.push_back(i+k);
  }
  
  return ret;
}
