#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

namespace haar_lib {
  template <typename Weight, typename Value>
  Value knapsack_small_quantity(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){
    const int p = N / 2;
    const int q = N - p;

    std::vector<std::pair<Weight, Value>> a, b;
    a.reserve(1 << p);
    b.reserve(1 << q);

    a.emplace_back(0, 0);
    b.emplace_back(0, 0);

    for(int i = 0; i < p; ++i){
      const int k = a.size();
      const auto begin = a.begin();
      const auto end = a.end();

      for(auto it = begin; it != end; ++it){
        a.emplace_back(it->first + w[i], it->second + v[i]);
      }

      std::inplace_merge(a.begin(), a.begin() + k, a.end());
    }

    for(int i = p; i < p + q; ++i){
      const int k = b.size();
      const auto begin = b.begin();
      const auto end = b.end();

      for(auto it = begin; it != end; ++it){
        b.emplace_back(it->first + w[i], it->second + v[i]);
      }

      std::inplace_merge(b.begin(), b.begin() + k, b.end());
    }

    for(size_t i = 1; i < a.size(); ++i){
      a[i].second = std::max(a[i].second, a[i - 1].second);
    }

    for(size_t i = 1; i < b.size(); ++i){
      b[i].second = std::max(b[i].second, b[i - 1].second);
    }

    Value ret = 0;

    for(int i = 0, j = (int)b.size() - 1; i < (int)a.size(); ++i){
      while(j >= 0 and a[i].first + b[j].first > cap) --j;
      if(j < 0) break;
      ret = std::max(ret, a[i].second + b[j].second);
    }

    return ret;
  }
}
