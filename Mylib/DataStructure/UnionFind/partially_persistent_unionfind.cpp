#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <numeric>

namespace haar_lib {
  class partially_persistent_unionfind {
    int N_, T_ = 0;
    std::vector<std::vector<std::pair<int, int>>> P_;
    std::vector<int> par_, rank_;

  public:
    partially_persistent_unionfind(){}
    partially_persistent_unionfind(int N): N_(N), P_(N), par_(N), rank_(N, 1){
      for(int i = 0; i < N_; ++i) P_[i].emplace_back(0, 1);
      std::iota(par_.begin(), par_.end(), 0);
    }

    int root_of(int i, int t){
      if(par_[i] == i) return i;

      if(P_[i].back().first == 0 or t < P_[i].back().first) return i;
      else if(t == P_[i].back().first) return P_[i].back().second;
      return root_of(par_[i], t);
    }

    bool is_same(int u, int v, int t){
      return root_of(u, t) == root_of(v, t);
    }

    int size_of(int u, int t){
      u = root_of(u, t);
      auto it = std::prev(std::lower_bound(P_[u].begin(), P_[u].end(), std::make_pair(t + 1, 0)));
      return it->second;
    }

    void merge(int u, int v){
      u = root_of(u, T_);
      v = root_of(v, T_);
      ++T_;

      if(u == v) return;

      const int s = size_of(u, T_ - 1) + size_of(v, T_ - 1);

      if(rank_[u] < rank_[v]){
        par_[u] = par_[v] = v;
        P_[u].emplace_back(T_, v);
        P_[v].emplace_back(T_, s);
      }else{
        par_[u] = par_[v] = u;
        P_[v].emplace_back(T_, u);
        P_[u].emplace_back(T_, s);
        if(rank_[u] == rank_[v]) ++rank_[u];
      }
    }
  };
}
