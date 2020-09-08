#pragma once
#include <vector>
#include <cstdint>
#include <cmath>
#include "Mylib/Number/Mod/mod_power.cpp"

/**
 * @title Graph vertex coloring
 * @docs chromatic_number.md
 */
namespace haar_lib {
  int chromatic_number(const std::vector<std::vector<int>> &graph){
    static constexpr int mod = 1000000007;
    const int N = graph.size();

    std::vector<int> g(N);
    for(int i = 0; i < N; ++i){
      for(auto j : graph[i]){
        g[i] |= (1 << j);
      }
    }

    std::vector<int64_t> I(1 << N);
    I[0] = 1;
    for(int i = 1; i < (1 << N); ++i){
      int c = __builtin_ctz(i);
      I[i] = I[i - (1 << c)] + I[(i - (1 << c)) & (~g[c])];
      if(I[i] >= mod) I[i] -= mod;
    }

    const auto check =
      [&](int k){
        int64_t t = 0;
        for(int i = 0; i < (1 << N); ++i){
          if(__builtin_popcount(i) % 2 == 1) t -= power(I[i], k, mod);
          else t += power(I[i], k, mod);
          if(t < 0) t += mod;
          if(t >= mod) t -= mod;
        }
        return (t % mod != 0);
      };

    int lb = 0, ub = N;
    while(std::abs(lb - ub) > 1){
      const auto mid = (lb + ub) / 2;

      if(check(mid)){
        ub = mid;
      }else{
        lb = mid;
      }
    }

    return ub;
  }
}
