#pragma once
#include <vector>
#include <cmath>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  class lowest_common_ancestor_doubling {
    int n_, log2n_;
    std::vector<std::vector<int>> parent_;
    std::vector<int> depth_;

    void dfs(const tree<T> &tr, int cur, int par, int d){
      parent_[cur][0] = par;
      depth_[cur] = d;

      for(auto &e : tr[cur]){
        if(e.to != par){
          dfs(tr, e.to, cur, d + 1);
        }
      }
    }

  public:
    lowest_common_ancestor_doubling(){}
    lowest_common_ancestor_doubling(const tree<T> &tr, int root):
      n_(tr.size()), log2n_((int)ceil(log2(n_)) + 1), parent_(n_, std::vector<int>(log2n_)), depth_(n_)
    {
      dfs(tr, root, -1, 0);
      for(int k = 0; k < log2n_ - 1; ++k){
        for(int v = 0; v < n_; ++v){
          if(parent_[v][k] == -1) parent_[v][k + 1] = -1;
          else parent_[v][k + 1] = parent_[parent_[v][k]][k];
        }
      }
    }

    int lca(int a, int b) const {
      if(depth_[a] >= depth_[b]) std::swap(a, b);
      for(int k = 0; k < log2n_; ++k){
        if((depth_[b] - depth_[a]) >> k & 1) b = parent_[b][k];
      }
      if(a == b) return a;
      for(int k = log2n_; --k >= 0;){
        if(parent_[a][k] != parent_[b][k]){a = parent_[a][k]; b = parent_[b][k];}
      }
      return parent_[a][0];
    }

    int operator()(int a, int b) const {return lca(a, b);}

    T distance(int u, int v, const std::vector<T> &dist) const {
      return dist[u] + dist[v] - 2 * dist[lca(u, v)];
    }
  };
}
