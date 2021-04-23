#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

namespace haar_lib {
  class unionfind {
    int n_, count_;
    mutable std::vector<int> parent_;
    std::vector<int> depth_, size_;

  public:
    unionfind() {}
    unionfind(int n) : n_(n), count_(n), parent_(n), depth_(n, 1), size_(n, 1) {
      std::iota(parent_.begin(), parent_.end(), 0);
    }

    int root_of(int i) const {
      if (parent_[i] == i)
        return i;
      else
        return parent_[i] = root_of(parent_[i]);
    }

    bool is_same(int i, int j) const { return root_of(i) == root_of(j); }

    int merge(int i, int j) {
      const int ri = root_of(i), rj = root_of(j);
      if (ri == rj)
        return ri;
      else {
        --count_;
        if (depth_[ri] < depth_[rj]) {
          parent_[ri] = rj;
          size_[rj] += size_[ri];
          return rj;
        } else {
          parent_[rj] = ri;
          size_[ri] += size_[rj];
          if (depth_[ri] == depth_[rj]) ++depth_[ri];
          return ri;
        }
      }
    }

    int size_of(int i) const { return size_[root_of(i)]; }

    int count_groups() const { return count_; }

    auto get_groups() const {
      std::vector<std::vector<int>> ret(n_);

      for (int i = 0; i < n_; ++i) {
        ret[root_of(i)].push_back(i);
      }

      ret.erase(
          std::remove_if(
              ret.begin(), ret.end(),
              [](const auto &a) { return a.empty(); }),
          ret.end());

      return ret;
    }
  };
}  // namespace haar_lib
