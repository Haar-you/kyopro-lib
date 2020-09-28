#pragma once
#include <vector>
#include <utility>

namespace haar_lib {
  template <typename T>
  class segment_tree_linear_add {
  public:
    using value_type = T;

  private:
    using P = std::pair<T, T>;

    int depth_, size_, hsize_;
    std::vector<P> data_;
    std::vector<int> from_;

    P add(P a, P b){
      return {a.first + b.first, a.second + b.second};
    }

    void propagate(int i){
      if(i < hsize_){
        data_[i << 1 | 0] = add(data_[i << 1 | 0], data_[i]);

        const int len = hsize_ >> (31 - __builtin_clz(i) + 1);
        data_[i].first += data_[i].second * len;
        data_[i << 1 | 1] = add(data_[i << 1 | 1], data_[i]);

        data_[i] = P();
      }
    }

    void propagate_top_down(int i){
      std::vector<int> temp;
      while(i > 1){
        i >>= 1;
        temp.push_back(i);
      }

      for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);
    }

  public:
    segment_tree_linear_add(){}
    segment_tree_linear_add(int n):
      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size_(1 << depth_), hsize_(size_ / 2),
      data_(size_, P()),
      from_(size_)
    {
      int s = 0;
      for(int i = 1; i < size_; ++i){
        from_[i] = s;
        int l = hsize_ >> (31 - __builtin_clz(i));
        s += l;
        if(s == hsize_) s = 0;
      }
    }

    void update(int l, int r, T a, T b){
      int L = l + hsize_;
      int R = r + hsize_;

      while(L < R){
        if(R & 1){
          --R;
          data_[R] = add(std::make_pair(b + a * (from_[R] - l), a), data_[R]);
        }
        if(L & 1){
          data_[L] = add(std::make_pair(b + a * (from_[L] - l), a), data_[L]);
          ++L;
        }
        L >>= 1;
        R >>= 1;
      }
    }

    T operator[](int i){
      propagate_top_down(i + hsize_);
      return data_[i + hsize_].first;
    }

    std::vector<T> get_all(int n){
      std::vector<T> ret(n);
      for(int i = 1; i < hsize_; ++i) propagate(i);
      for(int i = hsize_; i < hsize_ + n; ++i) ret[i - hsize_] = data_[i].first;
      return ret;
    }
  };
}
