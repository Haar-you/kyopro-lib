#pragma once
#include <utility>
#include <vector>

namespace haar_lib {
  class rollbackable_unionfind {
    int n_;
    std::vector<int> parent_, size_;
    std::vector<std::pair<int, int>> history_;

  public:
    rollbackable_unionfind() {}
    rollbackable_unionfind(int n) : n_(n), parent_(n, -1), size_(n, 1) {}

    int root_of(int i) const {
      if (parent_[i] == -1) return i;
      return root_of(parent_[i]);
    }

    bool is_same(int i, int j) const {
      return root_of(i) == root_of(j);
    }

    int merge(int i, int j) {
      const int ri = root_of(i), rj = root_of(j);

      history_.emplace_back(ri, size_[i]);
      history_.emplace_back(rj, size_[rj]);

      if (ri == rj) return ri;

      if (size_[ri] < size_[rj]) {
        parent_[ri] = rj;
        size_[rj] += size_[ri];
        return rj;
      } else {
        parent_[rj] = ri;
        size_[ri] += size_[rj];
        return ri;
      }
    }

    void roll_back() {
      for (int k = 0; k < 2; ++k) {
        auto [i, s] = history_.back();
        parent_[i]  = -1;
        size_[i]    = s;
        history_.pop_back();
      }
    }

    bool rollbackable() const {
      return not history_.empty();
    }

    int size_of(int i) const {
      return size_[root_of(i)];
    }

    void set_base() {
      history_.clear();
    }
  };
}  // namespace haar_lib
