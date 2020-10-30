#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

namespace haar_lib {
  class range_tree {
    using pll = std::pair<int64_t, int64_t>;
    friend class range_tree_builder;

    int size_;
    std::vector<int64_t> c_xs_;
    std::vector<std::vector<std::pair<int64_t, int>>> data_;

  public:
    auto get(pll s, pll t) const {
      const auto [sx, sy] = s;
      const auto [tx, ty] = t;

      std::vector<pll> ret;

      int L = std::lower_bound(c_xs_.begin(), c_xs_.end(), sx) - c_xs_.begin();
      int R = std::lower_bound(c_xs_.begin(), c_xs_.end(), tx) - c_xs_.begin();

      L += size_ / 2;
      R += size_ / 2;

      while(L < R){
        if(R & 1){
          auto &a = data_[--R];

          auto it = std::lower_bound(a.begin(), a.end(), std::make_pair(sy, 0));

          while(it != a.end()){
            if(it->first >= ty) break;

            ret.emplace_back(c_xs_[it->second], it->first);

            ++it;
          }
        }

        if(L & 1){
          auto &a = data_[L++];

          auto it = std::lower_bound(a.begin(), a.end(), std::make_pair(sy, 0));

          while(it != a.end()){
            if(it->first >= ty) break;

            ret.emplace_back(c_xs_[it->second], it->first);

            ++it;
          }
        }

        L >>= 1;
        R >>= 1;
      }

      return ret;
    }
  };

  class range_tree_builder {
    int N_ = 0;
    std::vector<int64_t> xs_, ys_;

  public:
    range_tree_builder(){}

    void add(int64_t x, int64_t y){
      ++N_;
      xs_.push_back(x);
      ys_.push_back(y);
    }

    auto build() const {
      range_tree ret;
      ret.c_xs_ = xs_;
      std::sort(ret.c_xs_.begin(), ret.c_xs_.end());
      ret.c_xs_.erase(std::unique(ret.c_xs_.begin(), ret.c_xs_.end()), ret.c_xs_.end());

      int M = ret.c_xs_.size();
      ret.size_ = 1 << (M > 1 ? 32 - __builtin_clz(M - 1) + 1 : 1);

      ret.data_.resize(ret.size_);

      for(int i = 0; i < N_; ++i){
        int j = std::lower_bound(ret.c_xs_.begin(), ret.c_xs_.end(), xs_[i]) - ret.c_xs_.begin();
        ret.data_[ret.size_ / 2 + j].emplace_back(ys_[i], j);
      }

      for(int i = ret.size_ / 2; i < ret.size_; ++i){
        std::sort(ret.data_[i].begin(), ret.data_[i].end());
      }

      for(int i = ret.size_ / 2 - 1; i > 0; --i){
        auto &a = ret.data_[i << 1 | 0];
        auto &b = ret.data_[i << 1 | 1];

        std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(ret.data_[i]));
      }

      return ret;
    }
  };
}
