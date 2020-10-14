#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>

namespace haar_lib {
  template <typename Monoid>
  class segment_tree {
  public:
    using value_type = typename Monoid::value_type;

  private:
    Monoid M_;
    int depth_, size_, hsize_;
    std::vector<value_type> data_;

  public:
    segment_tree(){}
    segment_tree(int n):
      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size_(1 << depth_), hsize_(size_ / 2),
      data_(size_, M_())
    {}

    auto operator[](int i) const {
      assert(0 <= i and i < hsize_);
      return data_[hsize_ + i];
    }

    auto fold(int l, int r) const {
      assert(0 <= l and l <= r and r <= hsize_);
      value_type ret_left = M_();
      value_type ret_right = M_();

      int L = l + hsize_, R = r + hsize_;
      while(L < R){
        if(R & 1) ret_right = M_(data_[--R], ret_right);
        if(L & 1) ret_left = M_(ret_left, data_[L++]);
        L >>= 1, R >>= 1;
      }

      return M_(ret_left, ret_right);
    }

    auto fold_all() const {
      return data_[1];
    }

    void set(int i, const value_type &x){
      assert(0 <= i and i < hsize_);
      i += hsize_;
      data_[i] = x;
      while(i > 1) i >>= 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);
    }

    void update(int i, const value_type &x){
      assert(0 <= i and i < hsize_);
      i += hsize_;
      data_[i] = M_(data_[i], x);
      while(i > 1) i >>= 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &val){
      data_.assign(size_, M_());
      for(int i = 0; i < (int)val.size(); ++i) data_[hsize_ + i] = val[i];
      for(int i = hsize_; --i >= 1;) data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);
    }

    template <typename T>
    void init(const T &val){
      init_with_vector(std::vector<value_type>(hsize_, val));
    }

  private:
    template <bool Lower, typename F>
    int bound(const int l, const int r, value_type x, F f) const {
      std::vector<int> pl, pr;
      int L = l + hsize_;
      int R = r + hsize_;
      while(L < R){
        if(R & 1) pr.push_back(--R);
        if(L & 1) pl.push_back(L++);
        L >>= 1, R >>= 1;
      }

      std::reverse(pr.begin(), pr.end());
      pl.insert(pl.end(), pr.begin(), pr.end());

      value_type a = M_();

      for(int i : pl){
        auto b = M_(a, data_[i]);

        if((Lower and not f(b, x)) or (not Lower and f(x, b))){
          while(i < hsize_){
            const auto c = M_(a, data_[i << 1 | 0]);
            if((Lower and not f(c, x)) or (not Lower and f(x, c))){
              i = i << 1 | 0;
            }else{
              a = c;
              i = i << 1 | 1;
            }
          }

          return i - hsize_;
        }

        a = b;
      }

      return r;
    }

  public:
    template <typename F = std::less<value_type>>
    int lower_bound(int l, int r, value_type x, F f = F()) const {
      return bound<true>(l, r, x, f);
    }

    template <typename F = std::less<value_type>>
    int upper_bound(int l, int r, value_type x, F f = F()) const {
      return bound<false>(l, r, x, f);
    }
  };
}
