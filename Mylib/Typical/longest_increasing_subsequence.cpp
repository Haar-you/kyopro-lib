#pragma once
#include <vector>
#include <algorithm>

namespace haar_lib {
  template <typename Container>
  std::vector<int> longest_increasing_subsequence(const Container &a){
    using T = typename Container::value_type;

    const int N = a.size();

    std::vector<T> dp;
    dp.reserve(N);
    std::vector<int> prev(N, -1), pos, ret;
    pos.reserve(N);

    for(int i = 0; i < N; ++i){
      auto x = a[i];
      if(dp.empty() or dp.back() < x){
        dp.push_back(x);
        if(pos.size()) prev[i] = pos.back();
        pos.push_back(i);
      }else{
        const int k = std::lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        dp[k] = x;
        if(k > 0) prev[i] = pos[k - 1];
        pos[k] = i;
      }
    }

    int i = pos.back();
    while(i != -1){
      ret.push_back(i);
      i = prev[i];
    }

    std::reverse(ret.begin(), ret.end());

    return ret;
  }
}
