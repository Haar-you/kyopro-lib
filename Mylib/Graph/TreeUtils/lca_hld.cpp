#pragma once
#include <vector>
#include <utility>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Lowest common ancestor (HLD)
 * @docs lca_hld.md
 */
namespace haar_lib {
  template <typename T>
  class lowest_common_ancestor_hld {
    int n;
    std::vector<int> sub, par, head, id;

    int dfs_sub(int cur, int p, tree<T> &tr){
      par[cur] = p;
      int t = 0;
      for(auto &e : tr[cur]){
        if(e.to == p) continue;
        sub[cur] += dfs_sub(e.to, cur, tr);
        if(sub[e.to] > t){
          t = sub[e.to];
          std::swap(e, tr[cur][0]);
        }
      }
      return sub[cur];
    }

    void dfs_build(int cur, int &i, tree<T> &tr){
      id[cur] = i;
      ++i;

      for(auto &e : tr[cur]){
        if(e.to == par[cur]) continue;
        head[e.to] = (e.to == tr[cur][0].to ? head[cur] : e.to);
        dfs_build(e.to, i, tr);
      }
    }

  public:
    lowest_common_ancestor_hld(tree<T> tr, int root):
      n(tr.size()), sub(n, 1), par(n, -1), head(n), id(n){
      dfs_sub(root, -1, tr);
      int i = 0;
      dfs_build(root, i, tr);
    }

    int lca(int u, int v) const {
      while(1){
        if(id[u] > id[v]) std::swap(u, v);
        if(head[u] == head[v]) return u;
        v = par[head[v]];
      }
    }

    int operator()(int u, int v) const {return lca(u, v);}

    T distance(int u, int v, const std::vector<T> &dist) const {
      return dist[u] + dist[v] - 2 * dist[lca(u, v)];
    }
  };
}
