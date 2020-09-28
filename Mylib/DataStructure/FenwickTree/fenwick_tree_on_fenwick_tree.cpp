#pragma once
#include <vector>
#include <numeric>
#include <algorithm>
#include "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"

namespace haar_lib {
  template <typename AbelianGroup>
  class fenwick_tree_on_fenwick_tree {
  public:
    using value_type = typename AbelianGroup::value_type;

  private:
    AbelianGroup G_;

    int N_ = 0;
    std::vector<int64_t> xs_, ys_;
    std::vector<int> c_xs_;
    std::vector<std::vector<int>> c_ys_;
    int x_size_;
    std::vector<fenwick_tree<AbelianGroup>> segs_;

  public:
    fenwick_tree_on_fenwick_tree(){}

    void add(int64_t x, int64_t y){
      xs_.push_back(x);
      ys_.push_back(y);
      ++N_;
    }

    void build(){
      c_xs_.insert(c_xs_.end(), xs_.begin(), xs_.end());

      std::sort(c_xs_.begin(), c_xs_.end());
      c_xs_.erase(std::unique(c_xs_.begin(), c_xs_.end()), c_xs_.end());

      x_size_ = c_xs_.size();

      c_ys_.resize(x_size_ + 1);
      segs_.resize(x_size_ + 1);

      std::vector<int> ord(N_);
      std::iota(ord.begin(), ord.end(), 0);
      std::sort(ord.begin(), ord.end(), [&](int i, int j){return ys_[i] < ys_[j];});
      for(auto i : ord){
        int x = std::lower_bound(c_xs_.begin(), c_xs_.end(), xs_[i]) - c_xs_.begin();

        for(x += 1; x <= x_size_; x += x & (-x)){
          c_ys_[x].emplace_back(ys_[i]);
        }
      }

      for(int i = 1; i <= x_size_; ++i){
        auto &a = c_ys_[i];
        a.erase(std::unique(a.begin(), a.end()), a.end());

        segs_[i] = fenwick_tree<AbelianGroup>(c_ys_[i].size());
      }
    }

    void update(std::pair<int, int> p, const value_type &val){
      const auto [x, y] = p;
      int i = std::lower_bound(c_xs_.begin(), c_xs_.end(), x) - c_xs_.begin();

      for(i += 1; i <= x_size_; i += i & (-i)){
        int j = std::lower_bound(c_ys_[i].begin(), c_ys_[i].end(), y) - c_ys_[i].begin();
        segs_[i].update(j, val);
      }
    }

  private:
    value_type get(int i, int64_t y1, int64_t y2) const {
      value_type ret = G_();
      for(; i > 0; i -= i & (-i)){
        int l = std::lower_bound(c_ys_[i].begin(), c_ys_[i].end(), y1) - c_ys_[i].begin();
        int r = std::lower_bound(c_ys_[i].begin(), c_ys_[i].end(), y2) - c_ys_[i].begin();
        ret = G_(ret, segs_[i].fold(l, r));
      }
      return ret;
    }

  public:
    // [x1, x2), [y1, y2)
    value_type fold(std::pair<int64_t, int64_t> p1, std::pair<int64_t, int64_t> p2) const {
      const auto [x1, y1] = p1;
      const auto [x2, y2] = p2;
      int l = std::lower_bound(c_xs_.begin(), c_xs_.end(), x1) - c_xs_.begin();
      int r = std::lower_bound(c_xs_.begin(), c_xs_.end(), x2) - c_xs_.begin();
      return G_(get(r, y1, y2), G_.inv(get(l, y1, y2)));
    }
  };
}
