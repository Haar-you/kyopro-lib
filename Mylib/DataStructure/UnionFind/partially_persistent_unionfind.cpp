#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <numeric>

/**
 * @title Partially persistent union-find
 * @docs partially_persistent_unionfind.md
 */
namespace haar_lib {
  class PartiallyPersistentUnionFind {
    int N;
    std::vector<std::vector<std::pair<int, int>>> P;
    std::vector<int> par;
    int T = 0;
    std::vector<int> rank;

  public:
    PartiallyPersistentUnionFind(int N): N(N), P(N), par(N), rank(N, 1){
      for(int i = 0; i < N; ++i) P[i].emplace_back(0, 1);
      std::iota(par.begin(), par.end(), 0);
    }

    int root_of(int i, int t){
      if(par[i] == i) return i;

      if(P[i].back().first == 0 || t < P[i].back().first) return i;
      else if(t == P[i].back().first) return P[i].back().second;
      return root_of(par[i], t);
    }

    bool is_same(int u, int v, int t){
      return root_of(u, t) == root_of(v, t);
    }

    int size_of(int u, int t){
      u = root_of(u, t);
      auto it = std::prev(std::lower_bound(P[u].begin(), P[u].end(), std::make_pair(t + 1, 0)));
      return it->second;
    }

    void merge(int u, int v){
      u = root_of(u, T);
      v = root_of(v, T);
      ++T;

      if(u == v) return;

      const int s = size_of(u, T - 1) + size_of(v, T - 1);

      if(rank[u] < rank[v]){
        par[u] = par[v] = v;
        P[u].emplace_back(T, v);
        P[v].emplace_back(T, s);
      }else{
        par[u] = par[v] = u;
        P[v].emplace_back(T, u);
        P[u].emplace_back(T, s);
        if(rank[u] == rank[v]) ++rank[u];
      }
    }
  };
}
