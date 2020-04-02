#pragma once
#include <vector>

/**
 * @title 最大独立集合
 * @see https://code-thanks-festival-2017-open.contest.atcoder.jp/submissions/4071345
 * @see https://codeforces.com/contest/1105/submission/48777508
 * @see https://judge.yosupo.jp/submission/1229
 * @attention 時間計算量はO(n*2^(n/2)) なのでn<=40程度まで許容
 * @attention 二部グラフでは、(最大独立集合の大きさ) = (グラフの大きさ) - (最大二部マッチングの大きさ)となるので、最大二部マッチングを用いる。
 */
int64_t maximum_independent_set(const std::vector<std::vector<int>> &graph){
  int n = graph.size();
  int h1 = n/2; //V1
  int h2 = n-h1; //V2

  std::vector<bool> dp1(1<<h1, true); // dp1[S] := Sが独立集合か?
  for(int i = 0; i < h1; ++i){
    for(auto j : graph[i]){
      if(j < h1) dp1[(1<<i) | (1<<j)] = false;
    }
  }
  
  for(int s = 0; s < (1<<h1); ++s){
    if(!dp1[s]){
      for(int j = 0; j < h1; ++j){
        dp1[s | (1<<j)] = false;
      }
    }
  }

  std::vector<bool> dp2(1<<h2, true); // dp2[S] := Sが独立集合か?
  for(int i = h1; i < n; ++i){
    for(auto j : graph[i]){
      if(j >= h1) dp2[(1<<(i-h1)) | (1<<(j-h1))] = false;
    }
  }

  for(int s = 0; s < (1<<h2); ++s){
    if(!dp2[s]){
      for(int j = 0; j < h2; ++j){
        dp2[s | (1<<j)] = false;
      }
    }
  }
  
  std::vector<int> dp3(1<<h1, 0); // S1と接続しないV2の最大の部分集合
  dp3[0] = (1<<h2)-1;
  for(int i = 0; i < h1; ++i){
    int t = 0;
    for(auto j : graph[i]){
      if(j >= h1){
        t |= (1<<(j-h1));
      }
    }
    dp3[1<<i] = t ^ ((1<<h2)-1);
  }
  
  for(int s = 0; s < (1<<h1); ++s){
    for(int j = 0; j < h1; ++j){
      if((s & (1<<j)) == 0){
        dp3[s | (1<<j)] = dp3[s] & dp3[1<<j];
      }
    }
  }

  std::vector<int> dp4(1<<h2, 0); // S2の最大独立集合
  for(int i = 0; i < (1<<h2); ++i){
    if(dp2[i]){
      dp4[i] = i;
    }
  }
  
  for(int s = 0; s < (1<<h2); ++s){
    for(int j = 0; j < h2; ++j){
      if((s & (1<<j)) == 0){
        if(__builtin_popcount(dp4[s | (1<<j)]) > __builtin_popcount(dp4[s])){
          dp4[s | (1<<j)] = dp4[s | (1<<j)];
        }else{
          dp4[s | (1<<j)] = dp4[s];
        }
      }
    }
  }
  
  int64_t ans = 0;
  int size = 0;
  
  for(int s = 0; s < (1<<h1); ++s){
    if(dp1[s]){
      int64_t t = (int64_t)s | (((int64_t)dp4[dp3[s]]) << h1);

      if(__builtin_popcountll(t) > size){
        size = __builtin_popcountll(t);
        ans = t;
      }
    }
  }
  
  return ans;
}
