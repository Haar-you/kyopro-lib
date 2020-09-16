#pragma once
#include <vector>
#include <cmath>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  class lowest_common_ancestor_doubling {
  private:
    std::vector<std::vector<int>> parent;
    int n, log2n;

    void dfs(const tree<T> &tr, int cur, int par, int d){
      parent[cur][0] = par;
      depth[cur] = d;

      for(auto &e : tr[cur]){
        if(e.to != par){
          dfs(tr, e.to, cur, d + 1);
        }
      }
    }

  public:
    std::vector<int> depth;

    lowest_common_ancestor_doubling(){}
    lowest_common_ancestor_doubling(const tree<T> &tr, int root):
      n(tr.size()), depth(n)
    {
      log2n = (int)ceil(log2(n)) + 1;
      parent = std::vector(n, std::vector<int>(log2n, 0));

      dfs(tr, root, -1, 0);
      for(int k = 0; k < log2n - 1; ++k){
        for(int v = 0; v < n; ++v){
          if(parent[v][k] == -1) parent[v][k + 1] = -1;
          else parent[v][k + 1] = parent[parent[v][k]][k];
        }
      }
    }

    int lca(int a, int b) const {
      if(depth[a] >= depth[b]) std::swap(a, b);
      for(int k = 0; k < log2n; ++k){
        if((depth[b] - depth[a]) >> k & 1) b = parent[b][k];
      }
      if(a == b) return a;
      for(int k = log2n; --k >= 0;){
        if(parent[a][k] != parent[b][k]){a = parent[a][k]; b = parent[b][k];}
      }
      return parent[a][0];
    }

    int operator()(int a, int b) const {return lca(a, b);}

    T distance(int u, int v, const std::vector<T> &dist) const {
      return dist[u] + dist[v] - 2 * dist[lca(u, v)];
    }
  };
}
