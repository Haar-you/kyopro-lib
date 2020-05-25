#pragma once
#include <vector>
#include <cmath>

/**
 * @title 並列二分探索
 * @docs parallel_binary_search.md
 */
template <typename F>
auto parallel_binary_search(int M, int Q, F f){
  std::vector<int> lb(Q, -1), ub(Q, M);

  while(1){
    bool check = true;
    std::vector<std::vector<int>> mids(M);
    for(int i = 0; i < Q; ++i){
      if(std::abs(lb[i] - ub[i]) > 1){
        check = false;
        int mid = (lb[i] + ub[i]) / 2;
        mids[mid].push_back(i);
      }
    }

    if(check) break;

    f(
      [&](auto process, auto checker){
        for(int i = 0; i < M; ++i){
          process(i);
          for(int j : mids[i]){
            if(checker(j)){
              ub[j] = i;
            }else{
              lb[j] = i;
            }
          }
        }
      }
    );
  }

  return ub;
}
