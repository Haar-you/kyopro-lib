#pragma once
#include <map>
#include <optional>
#include <vector>

namespace haar_lib {
  class undirected_eulerian_path {
    int n_, edges_;
    std::vector<std::map<int, int>> g_;
    std::vector<int> deg_;

    void del(int i, int j) {
      if (g_[i][j] == 1)
        g_[i].erase(j);
      else
        --g_[i][j];

      if (g_[j][i] == 1)
        g_[j].erase(i);
      else
        --g_[j][i];
    }

    void dfs(int cur, std::vector<int> &path) {
      if (not g_[cur].empty()) {
        int next = g_[cur].begin()->first;
        del(cur, next);
        dfs(next, path);
      }

      while (not g_[cur].empty()) {
        int next = g_[cur].begin()->first;
        del(cur, next);
        std::vector<int> temp;
        dfs(next, temp);
        path.insert(path.end(), temp.begin(), temp.end());
      }

      path.push_back(cur);
    }

  public:
    undirected_eulerian_path() {}
    undirected_eulerian_path(int n) : n_(n), edges_(0), g_(n), deg_(n) {}

    void add_edge(int i, int j) {
      ++g_[i][j];
      ++g_[j][i];
      ++deg_[i];
      ++deg_[j];
      ++edges_;
    }

    std::optional<std::vector<int>> eulerian_path() {
      std::vector<int> ret;

      int odd = 0, start = 0;
      for (int i = 0; i < n_; ++i) {
        if (deg_[i] % 2 == 1) {
          ++odd;
          start = i;
        }
      }

      if (odd != 0 and odd != 2) return std::nullopt;

      dfs(start, ret);

      if ((int) ret.size() == edges_ + 1) {
        return ret;
      } else {
        return std::nullopt;
      }
    }
  };
}  // namespace haar_lib
