#pragma once
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include <algorithm>
#include <vector>

namespace haar_lib {
  template <typename Monoid>
  class segment_tree_on_segment_tree {
  public:
    using value_type = typename Monoid::value_type;

  private:
    Monoid M_;
    int N_ = 0;
    std::vector<int64_t> xs_, ys_;
    std::vector<int> c_xs_;
    std::vector<std::vector<int>> c_ys_;
    int x_size_;
    std::vector<segment_tree<Monoid>> segs_;

  public:
    segment_tree_on_segment_tree() {}

    void add(int64_t x, int64_t y) {
      xs_.push_back(x);
      ys_.push_back(y);
      ++N_;
    }

    void build() {
      c_xs_.insert(c_xs_.end(), xs_.begin(), xs_.end());

      std::sort(c_xs_.begin(), c_xs_.end());
      c_xs_.erase(std::unique(c_xs_.begin(), c_xs_.end()), c_xs_.end());

      x_size_ = 1;
      while (x_size_ < (int) c_xs_.size()) x_size_ *= 2;
      x_size_ *= 2;

      c_ys_.resize(x_size_);
      segs_.resize(x_size_);

      for (int i = 0; i < N_; ++i) {
        int j = std::lower_bound(c_xs_.begin(), c_xs_.end(), xs_[i]) - c_xs_.begin();
        c_ys_[j + x_size_ / 2].push_back(ys_[i]);
      }

      for (int i = 0; i < x_size_ / 2; ++i) {
        auto &v = c_ys_[i + x_size_ / 2];
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
      }

      for (int i = x_size_ / 2 - 1; i >= 1; --i) {
        const auto &a = c_ys_[i << 1 | 0];
        const auto &b = c_ys_[i << 1 | 1];
        auto &c       = c_ys_[i];
        c.resize(a.size() + b.size());

        std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
        c.erase(std::unique(c.begin(), c.end()), c.end());
      }

      for (int i = 1; i < x_size_; ++i) {
        segs_[i] = segment_tree<Monoid>(c_ys_[i].size());
      }
    }

    void update(std::pair<int64_t, int64_t> p, const value_type &val) {
      const auto [x, y] = p;
      int i             = std::lower_bound(c_xs_.begin(), c_xs_.end(), x) - c_xs_.begin() + x_size_ / 2;

      while (i >= 1) {
        int j = std::lower_bound(c_ys_[i].begin(), c_ys_[i].end(), y) - c_ys_[i].begin();
        segs_[i].update(j, val);

        i >>= 1;
      }
    }

  private:
    value_type get_sub(int i, int64_t y1, int64_t y2) const {
      int l = std::lower_bound(c_ys_[i].begin(), c_ys_[i].end(), y1) - c_ys_[i].begin();
      int r = std::lower_bound(c_ys_[i].begin(), c_ys_[i].end(), y2) - c_ys_[i].begin();

      return segs_[i].fold(l, r);
    }

  public:
    value_type fold(std::pair<int64_t, int64_t> p1, std::pair<int64_t, int64_t> p2) const {
      const auto [x1, y1] = p1;
      const auto [x2, y2] = p2;
      int l               = std::lower_bound(c_xs_.begin(), c_xs_.end(), x1) - c_xs_.begin() + x_size_ / 2;
      int r               = std::lower_bound(c_xs_.begin(), c_xs_.end(), x2) - c_xs_.begin() + x_size_ / 2;

      value_type ret = M_();

      while (l < r) {
        if (r & 1) ret = M_(ret, get_sub(--r, y1, y2));
        if (l & 1) ret = M_(ret, get_sub(l++, y1, y2));
        l >>= 1;
        r >>= 1;
      }

      return ret;
    }
  };
}  // namespace haar_lib
