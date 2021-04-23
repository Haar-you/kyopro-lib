#pragma once
#include <cassert>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

namespace haar_lib {
  namespace push_relabel_impl {
    template <typename T>
    struct edge {
      int from, to, rev;
      T cap;
      bool is_rev;
      edge(int from, int to, int rev, T cap, bool is_rev) : from(from), to(to), rev(rev), cap(cap), is_rev(is_rev) {}
    };
  }  // namespace push_relabel_impl

  template <typename T>
  class push_relabel {
  public:
    using edge          = push_relabel_impl::edge<T>;
    using capacity_type = T;

  private:
    int N_;
    std::vector<std::vector<edge>> g_;
    std::vector<T> excess_;
    std::vector<int> height_;
    std::queue<int> next_active_vertex_;
    constexpr static T inf = std::numeric_limits<T>::max();

    void init(int s, int t) {
      excess_[s] = inf;

      for (auto &e : g_[s]) {
        push(e, s, t);
      }

      {
        for (int i = 0; i < N_; ++i) {
          height_[i] = N_;
        }

        std::queue<int> q;
        std::vector<bool> check(N_);
        q.push(t);
        height_[t] = 0;

        while (not q.empty()) {
          const int i = q.front();
          q.pop();

          if (check[i]) continue;
          check[i] = true;

          for (auto &e : g_[i]) {
            if (not e.is_rev) continue;
            if (height_[e.from] + 1 < height_[e.to]) {
              height_[e.to] = height_[e.from] + 1;
              q.push(e.to);
            }
          }
        }

        height_[s] = N_;
      }
    }

    bool is_pushable(const edge &e) {
      if (excess_[e.from] == 0) return false;
      if (height_[e.from] != height_[e.to] + 1) return false;
      if (e.cap == 0) return false;
      return true;
    }

    void push(edge &e, int, int) {
      auto &r = g_[e.to][e.rev];

      T flow = std::min(e.cap, excess_[e.from]);

      e.cap -= flow;
      r.cap += flow;

      excess_[e.from] -= flow;
      excess_[e.to] += flow;

      if (excess_[e.to] == flow) next_active_vertex_.push(e.to);
    }

    void relabel(int i, int, int) {
      int a = std::numeric_limits<int>::max() / 2;
      for (auto &e : g_[i]) {
        if (e.cap > 0) a = std::min(a, height_[e.to]);
      }

      height_[i] = a + 1;
    }

  public:
    push_relabel() {}
    push_relabel(int N) : N_(N), g_(N), excess_(N), height_(N) {}

    void add_edge(int from, int to, T c) {
      assert(0 <= from and from < N_);
      assert(0 <= to and to < N_);
      g_[from].emplace_back(from, to, (int) g_[to].size(), c, false);
      g_[to].emplace_back(to, from, (int) g_[from].size() - 1, 0, true);
    }

    T max_flow(int s, int t) {
      assert(0 <= s and s < N_);
      assert(0 <= t and t < N_);
      init(s, t);

      while (true) {
        int index = -1;

        while (not next_active_vertex_.empty()) {
          int i = next_active_vertex_.front();
          if (i != s and i != t and excess_[i] > 0) {
            index = i;
            break;
          }
          next_active_vertex_.pop();
        }

        if (index == -1) break;

        bool ok = false;
        for (auto &e : g_[index]) {
          if (is_pushable(e)) {
            push(e, s, t);
            ok = true;
            break;
          }
        }

        if (not ok) {
          relabel(index, s, t);
        }
      }

      return excess_[t];
    }

    std::vector<edge> edges() const {
      std::vector<edge> ret;
      for (auto &v : g_) ret.insert(ret.end(), v.begin(), v.end());
      return ret;
    }
  };
}  // namespace haar_lib
