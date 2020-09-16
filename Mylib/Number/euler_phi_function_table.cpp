#pragma once
#include <vector>
#include <numeric>

namespace haar_lib {
  auto totient_table(int n){
    std::vector<int> ret(n + 1);
    std::iota(ret.begin(), ret.end(), 0);

    for(int i = 2; i <= n; ++i){
      if(ret[i] == i){
        for(int j = i; j <= n; j += i){
          ret[j] = ret[j] / i * (i - 1);
        }
      }
    }

    return ret;
  }
}
