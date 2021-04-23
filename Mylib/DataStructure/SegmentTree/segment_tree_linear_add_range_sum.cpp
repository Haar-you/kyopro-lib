#pragma once
#include <utility>
#include <vector>

namespace haar_lib {
  template <typename T>
  class segment_tree_linear_add_range_sum {
  public:
    using value_type = T;

  private:
    using P = std::pair<T, T>;

    int depth_, size_, hsize_;
    std::vector<T> data_;
    std::vector<P> lazy_;

  public:
    segment_tree_linear_add_range_sum() {}
    segment_tree_linear_add_range_sum(int n) : depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
                                               size_(1 << depth_),
                                               hsize_(size_ / 2),
                                               data_(size_, T()),
                                               lazy_(size_, P()) {}

  private:
    P add(P a, P b) {
      return {a.first + b.first, a.second + b.second};
    }

    void propagate(int i, int l, int r) {
      if (lazy_[i] == P()) return;
      if (i < hsize_) {
        auto t            = lazy_[i];
        lazy_[i << 1 | 0] = add(t, lazy_[i << 1 | 0]);
        t.first += t.second * ((r - l) / 2);
        lazy_[i << 1 | 1] = add(t, lazy_[i << 1 | 1]);
      }
      const int len     = r - l;
      const auto [s, d] = lazy_[i];
      data_[i] += len * (s * 2 + d * (len - 1)) / 2;
      lazy_[i] = P();
    }

    T update(int i, int l, int r, int s, int t, T a, T b) {
      propagate(i, l, r);
      if (r <= s or t <= l) return data_[i];
      if (s <= l and r <= t) {
        lazy_[i] = add(lazy_[i], std::make_pair(b + (l - s) * a, a));
        propagate(i, l, r);
        return data_[i];
      }
      return data_[i] =
                 update(i << 1 | 0, l, (l + r) / 2, s, t, a, b) +
                 update(i << 1 | 1, (l + r) / 2, r, s, t, a, b);
    }

    T get(int i, int l, int r, int x, int y) {
      propagate(i, l, r);
      if (r <= x or y <= l) return 0;
      if (x <= l and r <= y) return data_[i];
      return get(i << 1 | 0, l, (l + r) / 2, x, y) +
             get(i << 1 | 1, (l + r) / 2, r, x, y);
    }

  public:
    void update(int l, int r, T a, T b) {
      update(1, 0, hsize_, l, r, a, b);
    }

    T fold(int l, int r) {
      return get(1, 0, hsize_, l, r);
    }

    T operator[](int i) {
      return fold(i, i + 1);
    }
  };
}  // namespace haar_lib
