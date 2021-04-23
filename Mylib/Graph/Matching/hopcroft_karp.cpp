#pragma once
#include <cassert>
#include <queue>
#include <utility>
#include <vector>

namespace haar_lib {
  class hopcroft_karp {
    struct edge {
      int from, to;
      int rev;
      bool used;
    };

    int L_, R_, N_;
    std::vector<std::vector<edge>> g_;
    std::vector<int> dist_;

    bool bfs() {
      dist_.assign(N_, -1);
      std::queue<int> q;

      q.push(0);
      dist_[0] = 0;

      while (not q.empty()) {
        int i = q.front();
        q.pop();

        for (auto &e : g_[i]) {
          if (not e.used and dist_[e.to] == -1) {
            dist_[e.to] = dist_[i] + 1;
            q.push(e.to);
          }
        }
      }

      return dist_[N_ - 1] != -1;
    }

    bool dfs(int cur) {
      if (cur == N_ - 1) return true;

      for (auto &e : g_[cur]) {
        if (not e.used and dist_[cur] + 1 == dist_[e.to]) {
          if (dfs(e.to)) {
            e.used = true;
            if (e.rev >= 0) g_[e.to][e.rev].used = false;
            return true;
          }
        }
      }

      return false;
    }

  public:
    hopcroft_karp() {}
    hopcroft_karp(int L, int R) : L_(L), R_(R), N_(L + R + 2), g_(N_), dist_(N_) {
      for (int i = 0; i < L_; ++i) {
        g_[0].push_back((edge){0, i + 1, -1, false});
      }

      for (int i = 0; i < R_; ++i) {
        g_[i + L_ + 1].push_back((edge){i + L_ + 1, N_ - 1, -1, false});
      }
    }

    void add_edge(int i, int j) {
      assert(0 <= i and i < L_);
      assert(0 <= j and j < R_);

      const int x = i + 1;
      const int y = j + L_ + 1;

      g_[x].push_back((edge){x, y, (int) g_[y].size(), false});
      g_[y].push_back((edge){y, x, (int) g_[x].size() - 1, true});
    }

    int match() {
      int ret = 0;

      while (bfs()) {
        int flow = 0;
        for (int i = 0; i < L_; ++i) {
          auto &e = g_[0][i];
          if (not e.used and dfs(e.to)) {
            e.used = true;
            ++flow;
          }
        }
        if (flow == 0) break;
        ret += flow;
      }

      return ret;
    }

    auto get_matching() {
      std::vector<std::pair<int, int>> ret;
      for (int i = 0; i < L_; ++i) {
        for (auto &e : g_[i + 1]) {
          if (e.used) ret.emplace_back(i, e.to - L_ - 1);
        }
      }
      return ret;
    }
  };
}  // namespace haar_lib
