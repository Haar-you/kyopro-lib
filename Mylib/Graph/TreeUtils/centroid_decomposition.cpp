#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  class centroid_decomposition {
    int N_;
    std::vector<int> parent_, subsize_;
    std::vector<std::vector<int>> children_;
    std::vector<bool> check_;

  public:
    centroid_decomposition() {}
    centroid_decomposition(const tree<T> &tr) : N_(tr.size()), parent_(N_), subsize_(N_), children_(N_), check_(N_) {
      decompose(tr, 0, -1);
    }

  private:
    void decompose(const tree<T> &tr, int cur, int par) {
      dfs_subsize(tr, cur, -1);
      auto c = get_centroid(tr, cur, -1, subsize_[cur]);

      check_[c]  = true;
      parent_[c] = par;
      if (par != -1) children_[par].push_back(c);

      for (auto &e : tr[c]) {
        if (check_[e.to]) continue;
        decompose(tr, e.to, c);
      }
    }

    int get_centroid(const tree<T> &tr, int cur, int par, int total_size) {
      for (auto &e : tr[cur]) {
        if (e.to == par or check_[e.to]) continue;

        if (2 * subsize_[e.to] > total_size) {
          return get_centroid(tr, e.to, cur, total_size);
        }
      }

      return cur;
    }

    void dfs_subsize(const tree<T> &tr, int cur, int par) {
      subsize_[cur] = 1;
      for (auto &e : tr[cur]) {
        if (e.to == par or check_[e.to]) continue;
        dfs_subsize(tr, e.to, cur);
        subsize_[cur] += subsize_[e.to];
      }
    }

  public:
    auto bottom_up(int i) const {
      std::vector<int> ret;
      while (i >= 0) {
        ret.push_back(i);
        i = parent_[i];
      }
      return ret;
    }
  };
}  // namespace haar_lib
