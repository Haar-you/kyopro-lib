#pragma once
#include <utility>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  class lowest_common_ancestor_hld {
    int n_;
    std::vector<int> sub_, par_, head_, id_;

    int dfs_sub(int cur, int p, tree<T> &tr) {
      par_[cur] = p;
      int t     = 0;
      for (auto &e : tr[cur]) {
        if (e.to == p) continue;
        sub_[cur] += dfs_sub(e.to, cur, tr);
        if (sub_[e.to] > t) {
          t = sub_[e.to];
          std::swap(e, tr[cur][0]);
        }
      }
      return sub_[cur];
    }

    void dfs_build(int cur, int &i, tree<T> &tr) {
      id_[cur] = i;
      ++i;

      for (auto &e : tr[cur]) {
        if (e.to == par_[cur]) continue;
        head_[e.to] = (e.to == tr[cur][0].to ? head_[cur] : e.to);
        dfs_build(e.to, i, tr);
      }
    }

  public:
    lowest_common_ancestor_hld() {}
    lowest_common_ancestor_hld(tree<T> tr, int root) : n_(tr.size()), sub_(n_, 1), par_(n_, -1), head_(n_), id_(n_) {
      dfs_sub(root, -1, tr);
      int i = 0;
      dfs_build(root, i, tr);
    }

    int lca(int u, int v) const {
      while (1) {
        if (id_[u] > id_[v]) std::swap(u, v);
        if (head_[u] == head_[v]) return u;
        v = par_[head_[v]];
      }
    }

    int operator()(int u, int v) const { return lca(u, v); }

    T distance(int u, int v, const std::vector<T> &dist) const {
      return dist[u] + dist[v] - 2 * dist[lca(u, v)];
    }
  };
}  // namespace haar_lib
