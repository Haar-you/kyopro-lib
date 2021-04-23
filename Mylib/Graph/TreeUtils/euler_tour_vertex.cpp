#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  class euler_tour_vertex {
    int pos_ = 0;
    std::vector<int> begin_, end_;

    void dfs(int cur, int par, const tree<T> &tr) {
      begin_[cur] = pos_++;

      for (auto &e : tr[cur]) {
        if (e.to == par) continue;
        dfs(e.to, cur, tr);
      }

      end_[cur] = pos_;
    }

  public:
    euler_tour_vertex() {}
    euler_tour_vertex(const tree<T> &tr, int root) : begin_(tr.size()), end_(tr.size()) {
      dfs(root, -1, tr);
    }

    template <typename F>  // F = std::function<void(int, int)>
    void subtree_query(int i, const F &f) {
      f(begin_[i], end_[i]);
    }

    template <typename F>  // F = std::function<void(int)>
    void point_query(int i, const F &f) {
      f(begin_[i]);
    }
  };
}  // namespace haar_lib
