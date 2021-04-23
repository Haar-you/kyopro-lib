#pragma once
#include <queue>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  class pseudo_tree {
    int n_;
    std::vector<bool> in_loop_;
    std::vector<int> group_;

    void dfs(int cur, int par, const graph<T> &g) {
      group_[cur] = group_[par];

      for (auto &e : g[cur]) {
        if (e.to == par) continue;
        dfs(e.to, cur, g);
      }
    }

  public:
    pseudo_tree() {}
    pseudo_tree(const graph<T> &g) : n_(g.size()), in_loop_(n_, true), group_(n_) {
      std::vector<int> indeg(n_);
      std::vector<bool> visited(n_);
      std::queue<int> q;

      for (int i = 0; i < n_; ++i) {
        for (auto &e : g[i]) {
          ++indeg[e.to];
        }
      }

      for (int i = 0; i < n_; ++i) {
        if (indeg[i] == 1) {
          q.push(i);
        }
      }

      while (not q.empty()) {
        int cur = q.front();
        q.pop();

        in_loop_[cur] = false;

        if (visited[cur]) continue;
        visited[cur] = true;

        for (auto &e : g[cur]) {
          if (not visited[e.to]) {
            --indeg[e.to];
            if (indeg[e.to] == 1) {
              q.push(e.to);
            }
          }
        }
      }

      for (int i = 0; i < n_; ++i) {
        if (in_loop_[i]) {
          group_[i] = i;
          for (auto &e : g[i]) {
            if (not in_loop_[e.to]) {
              dfs(e.to, i, g);
            }
          }
        }
      }
    }

    bool in_loop(int i) const { return in_loop_[i]; }
    int group(int i) const { return group_[i]; }
  };
}  // namespace haar_lib
