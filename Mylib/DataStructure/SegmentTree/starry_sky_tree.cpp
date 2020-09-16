#pragma once
#include <vector>
#include <optional>
#include <algorithm>

namespace haar_lib {
  template <typename T, typename Compare>
  class starry_sky_tree {
    int depth, size, hsize;
    std::vector<T> data;

    Compare compare = Compare();

    T f(T a, T b) const {
      return compare(a, b) ? a : b;
    }

    void bottom_up(int i){
      if(i > size) return;

      while(i >= 1){
        if(i < hsize){
          const auto d = f(data[i << 1 | 0], data[i << 1 | 1]);

          data[i << 1 | 0] -= d;
          data[i << 1 | 1] -= d;
          data[i] += d;
        }

        i >>= 1;
      }
    }

    std::optional<T> get(int i, int l, int r, int s, int t, T val) const {
      if(r <= s or t <= l) return std::nullopt;
      if(s <= l and r <= t) return val + data[i];

      auto a = get(i << 1 | 0, l, (l + r) / 2, s, t, val + data[i]);
      auto b = get(i << 1 | 1, (l + r) / 2, r, s, t, val + data[i]);

      if(not a) return b;
      if(not b) return a;
      return f(*a, *b);
    }

  public:
    starry_sky_tree(int n):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth),
      hsize(size / 2),
      data(size, 0)
    {}

    void update(int l, int r, T val){
      int L = l + hsize;
      int R = r + hsize;

      while(L < R){
        if(R & 1) --R, data[R] += val;
        if(L & 1) data[L] += val, ++L;
        L >>= 1;
        R >>= 1;
      }

      bottom_up(l + hsize);
      bottom_up(r + hsize);
    }

    T get(int l, int r) const {
      return *get(1, 0, hsize, l, r, 0);
    }

    template <typename U>
    void init_with_vector(std::vector<U> &a){
      for(int i = 0; i < (int)a.size(); ++i){
        data[hsize + i] = a[i];
      }

      for(int i = hsize - 1; i >= 1; --i){
        data[i] = f(data[i << 1 | 0], data[i << 1 | 1]);
      }

      for(int i = size - 1; i > 1; --i){
        data[i] -= data[i >> 1];
      }
    }
  };
}
