#pragma once
#include <utility>
#include <vector>
#include <algorithm>
#include <optional>

namespace haar_lib {
  template <typename T, typename Comparator>
  class lichao_segment_tree {
  public:
    using value_type = T;

  private:
    using line = std::pair<T, T>;

    Comparator cmp_ = Comparator();
    std::vector<T> xs_;
    int n_;
    std::vector<std::optional<line>> data_;
    std::vector<std::pair<int, int>> range_;

    T chm(const T &a, const T &b) const {
      return cmp_(a, b) ? a : b;
    }

    void init_range_(int i, int left, int right){
      if(i >= 2 * n_) return;

      range_[i] = std::make_pair(left, right);
      const int mid = (left + right) / 2;
      init_range_(i << 1 | 0, left, mid);
      init_range_(i << 1 | 1, mid, right);
    }

  public:
    lichao_segment_tree(){}
    lichao_segment_tree(std::vector<T> xs): xs_(xs){
      std::sort(xs_.begin(), xs_.end());
      xs_.erase(std::unique(xs_.begin(), xs_.end()), xs_.end());

      n_ = 1;
      while(n_ < (int)xs_.size()) n_ *= 2;

      const auto m = xs_.back();
      xs_.resize(n_, m);

      data_.assign(2 * n_, std::nullopt);

      range_.resize(2 * n_);
      init_range_(1, 0, n_);
    }

    T apply(const line &l, const T &x) const {
      return l.first * x + l.second;
    }

  private:
    void update(int i, line new_line, int l, int r){
      if(not data_[i]){
        data_[i] = new_line;
        return;
      }

      const int m = (l + r) / 2;

      auto lx = xs_[l], mx = xs_[m], rx = xs_[r - 1];

      bool left = cmp_(apply(new_line, lx), apply(*data_[i], lx));
      bool mid = cmp_(apply(new_line, mx), apply(*data_[i], mx));
      bool right = cmp_(apply(new_line, rx), apply(*data_[i], rx));

      if(left and right){
        data_[i] = new_line;
        return;
      }

      if(not left and not right){
        return;
      }

      if(mid){
        std::swap(*data_[i], new_line);
      }

      if(left != mid){
        update(i << 1 | 0, new_line, l, m);
      }else{
        update(i << 1 | 1, new_line, m, r);
      }
    }

  public:
    void add_line(T a, T b){
      update(1, std::make_pair(a, b), 0, n_);
    }

    // [l, r)
    void add_segment(T l, T r, T a, T b){
      int left = std::lower_bound(xs_.begin(), xs_.end(), l) - xs_.begin();
      int right = std::lower_bound(xs_.begin(), xs_.end(), r) - xs_.begin();

      int L = left + n_;
      int R = right + n_;

      while(L < R){
        if(R & 1){
          --R;
          update(R, std::make_pair(a, b), range_[R].first, range_[R].second);
        }

        if(L & 1){
          update(L, std::make_pair(a, b), range_[L].first, range_[L].second);
          ++L;
        }

        L >>= 1;
        R >>= 1;
      }
    }

  public:
    auto operator()(const T &x) const {
      const int i = std::lower_bound(xs_.begin(), xs_.end(), x) - xs_.begin();
      int k = i + n_;

      std::optional<T> ret;

      while(k > 0){
        if(data_[k]){
          if(not ret) ret = apply(*data_[k], xs_[i]);
          else ret = chm(*ret, apply(*data_[k], xs_[i]));
        }
        k >>= 1;
      }

      return ret;
    }
  };

  template <typename T>
  auto make_lichao_min(const std::vector<T> &xs){
    return lichao_segment_tree<T, std::less<T>>(xs);
  }

  template <typename T>
  auto make_lichao_max(const std::vector<T> &xs){
    return lichao_segment_tree<T, std::greater<T>>(xs);
  }
}
