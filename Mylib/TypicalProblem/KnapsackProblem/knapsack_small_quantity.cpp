#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

/**
 * @title 個数の制約が小さい0-1ナップサック問題 (半分全列挙)
 * @attention 時間計算量 O(2^(N/2) log(2^(N/2)))
 */
template <typename Weight, typename Value>
Value knapsack_small_quantity(int N, Weight W, const std::vector<Weight> &w, const std::vector<Value> &v){
  Value ret = 0;

  int p = N/2;
  int q = N-p;

  std::map<Weight, Value> a;
  for(int i = 0; i < 1<<p; ++i){
    Weight weight = 0;
    Value value = 0;
    for(int j = 0; j < p; ++j){
      if(i & (1<<j)){
        weight += w[j];
        value += v[j];
      }
    }

    a[weight] = std::max(a[weight], value);
  }

  Value m = 0;
  for(auto &kv : a){
    kv.second = std::max(kv.second, m);
    m = kv.second;
  }
  
  
  for(int i = 0; i < 1<<q; ++i){
    Weight weight = 0;
    Value value = 0;
    for(int j = 0; j < q; ++j){
      if(i&(1<<j)){
        weight += w[j+p];
        value += v[j+p];
      }
    }

    auto itr = a.upper_bound(std::max(0LL, W-weight));
    
    itr = std::prev(itr);
    if(weight + itr->first <= W) ret = std::max(ret, value + itr->second);
  }

  return ret;
}
