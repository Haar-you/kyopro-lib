#pragma once
#include <vector>
#include <optional>
#include <algorithm>
#include <cassert>

namespace haar_lib {
  template <typename T, typename Compare>
  class starry_sky_tree {
  public:
    using value_type = T;

  private:
    int depth_, size_, hsize_;
    std::vector<T> data_;
    Compare compare_ = Compare();

    T f(T a, T b) const {
      return compare_(a, b) ? a : b;
    }

    void bottom_up(int i){
      if(i > size_) return;

      while(i >= 1){
        if(i < hsize_){
          const auto d = f(data_[i << 1 | 0], data_[i << 1 | 1]);

          data_[i << 1 | 0] -= d;
          data_[i << 1 | 1] -= d;
          data_[i] += d;
        }

        i >>= 1;
      }
    }

    std::optional<T> get(int i, int l, int r, int s, int t, T val) const {
      if(r <= s or t <= l) return std::nullopt;
      if(s <= l and r <= t) return val + data_[i];

      auto a = get(i << 1 | 0, l, (l + r) / 2, s, t, val + data_[i]);
      auto b = get(i << 1 | 1, (l + r) / 2, r, s, t, val + data_[i]);

      if(not a) return b;
      if(not b) return a;
      return f(*a, *b);
    }

  public:
    starry_sky_tree(){}
    starry_sky_tree(int n):
      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size_(1 << depth_),
      hsize_(size_ / 2),
      data_(size_, 0)
    {}

    void update(int l, int r, T val){
      assert(0 <= l and l <= r and r <= hsize_);
      int L = l + hsize_;
      int R = r + hsize_;

      while(L < R){
        if(R & 1) --R, data_[R] += val;
        if(L & 1) data_[L] += val, ++L;
        L >>= 1;
        R >>= 1;
      }

      bottom_up(l + hsize_);
      bottom_up(r + hsize_);
    }

    T fold(int l, int r) const {
      assert(0 <= l and l <= r and r <= hsize_);
      return *get(1, 0, hsize_, l, r, 0);
    }

    T fold_all() const {
      return data_[1];
    }

    template <typename U>
    void init_with_vector(std::vector<U> &a){
      for(int i = 0; i < (int)a.size(); ++i){
        data_[hsize_ + i] = a[i];
      }

      for(int i = hsize_; --i >= 1;){
        data_[i] = f(data_[i << 1 | 0], data_[i << 1 | 1]);
      }

      for(int i = size_; --i > 1;){
        data_[i] -= data_[i >> 1];
      }
    }
  };
}
