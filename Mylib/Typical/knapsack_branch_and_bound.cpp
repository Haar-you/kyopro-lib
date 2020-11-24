#pragma once

#include <vector>
#include <algorithm>
#include <numeric>

namespace haar_lib {
  template <typename Weight, typename Value>
  Value knapsack_branch_and_bound(
    int N, Weight cap, const std::vector<Weight> &weight, const std::vector<Value> &value
  ){
    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);

    std::sort(
      ord.begin(), ord.end(),
      [&](int i, int j){
        return (double)value[i] / weight[i] > (double)value[j] / weight[j];
      }
    );

    Value feasible_sol = 0;

    auto dfs =
      [&](auto &dfs, int k, Weight w, Value v) -> Value {
        if(w > cap) return 0;
        if(k == N){
          feasible_sol = std::max(feasible_sol, v);
          return v;
        }

        bool is_opt = true;
        Value sol = 0;
        Weight w_sum = 0;
        int p = 0;

        for(p = k; p < N; ++p){
          if(w_sum + weight[ord[p]] >= cap - w){
            if(w_sum + weight[ord[p]] == cap - w){
              w_sum += weight[ord[p]];
              sol += value[ord[p]];
            }else{
              is_opt = false;
            }

            break;
          }else{
            w_sum += weight[ord[p]];
            sol += value[ord[p]];
          }
        }

        if(is_opt) return feasible_sol = std::max(feasible_sol, v + sol);

        double d = (double)value[ord[p]] / weight[ord[p]] * (cap - w - w_sum) ;
        if((double)v + sol + d < feasible_sol){
          return 0;
        }

        Value ret = 0;

        if(w + weight[ord[k]] <= cap){
          ret = std::max(ret, dfs(dfs, k + 1, w + weight[ord[k]], v + value[ord[k]]));
          feasible_sol = std::max(feasible_sol, ret);
        }

        ret = std::max(ret, dfs(dfs, k + 1, w, v));
        feasible_sol = std::max(feasible_sol, ret);

        return ret;
      };

    auto ret = dfs(dfs, 0, 0, 0);
    return ret;
  }
}
