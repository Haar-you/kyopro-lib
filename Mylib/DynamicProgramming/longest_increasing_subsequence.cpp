#pragma once
#include <vector>
#include <algorithm>

namespace haar_lib {
  template <typename Container, typename T = typename Container::value_type>
  int lis(const Container &xs){
    std::vector<T> dp;
    dp.reserve(xs.size());

    for(auto x : xs){
      if(dp.empty() or dp.back() < x){
        dp.push_back(x);
      }else{
        dp[std::lower_bound(dp.begin(), dp.end(), x) - dp.begin()] = x;
      }
    }

    return dp.size();
  }
}
