#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <numeric>

/**
 * @brief 部分永続Unionfind
 * @see https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/7720761
 * @see https://atcoder.jp/contests/agc002/submissions/7720745
 */
class PartiallyPersistentUnionFind{
  int N;
  std::vector<std::vector<std::pair<int,int>>> P;
  std::vector<int> par;
  int T = 0;
  std::vector<int> rank;

public:
  PartiallyPersistentUnionFind(int N): N(N), P(N), par(N), rank(N,1){
    for(int i = 0; i < N; ++i) P[i].push_back({0,1});
    std::iota(par.begin(), par.end(), 0);
  }
  
  int get_root(int i, int t){
    if(par[i] == i) return i;

    if(P[i].back().first == 0 || t < P[i].back().first) return i;
    else if(t == P[i].back().first) return P[i].back().second;
    else return get_root(par[i],t);
  }

  bool is_same(int u, int v, int t){
    return get_root(u,t) == get_root(v,t);
  }

  int size(int u, int t){
    u = get_root(u,t);
    auto it = std::prev(std::lower_bound(P[u].begin(), P[u].end(), std::make_pair(t+1,0)));
    return it->second;
  }

  void merge(int u, int v){
    u = get_root(u,T);
    v = get_root(v,T);
    ++T;

    if(u==v) return;

    int s = size(u,T-1) + size(v,T-1);
    
    if(rank[u] < rank[v]){
      par[u] = par[v] = v;
      P[u].push_back({T,v});
      P[v].push_back({T,s});
    }else{
      par[u] = par[v] = u;
      P[v].push_back({T,u});
      P[u].push_back({T,s});
      if(rank[u] == rank[v]) ++rank[u];
    }
  }
};
