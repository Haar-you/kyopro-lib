#pragma once
#include <vector>
#include <utility>

namespace haar_lib {
  template <typename T>
  class segment_tree_linear_add_range_sum {
    using P = std::pair<T, T>;

    int depth, size, hsize;
    std::vector<T> data;
    std::vector<P> lazy;

  public:
    segment_tree_linear_add_range_sum(){}
    segment_tree_linear_add_range_sum(int n):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth), hsize(size / 2),
      data(size, T()),
      lazy(size, P())
    {}

  private:
    P add(P a, P b){
      return {a.first + b.first, a.second + b.second};
    }

    void propagate(int i, int l, int r){
      if(lazy[i] == P()) return;
      if(i < hsize){
        auto t = lazy[i];
        lazy[i << 1 | 0] = add(t, lazy[i << 1 | 0]);
        t.first += t.second * ((r - l) / 2);
        lazy[i << 1 | 1] = add(t, lazy[i << 1 | 1]);
      }
      const int len = r - l;
      const auto [s, d] = lazy[i];
      data[i] += len * (s * 2 + d * (len - 1)) / 2;
      lazy[i] = P();
    }

    T update(int i, int l, int r, int s, int t, T a, T b){
      propagate(i, l, r);
      if(r <= s or t <= l) return data[i];
      if(s <= l and r <= t){
        lazy[i] = add(lazy[i], std::make_pair(b + (l - s) * a, a));
        propagate(i, l, r);
        return data[i];
      }
      return data[i] =
        update(i << 1 | 0, l, (l + r) / 2, s, t, a, b) +
        update(i << 1 | 1, (l + r) / 2, r, s, t, a, b);
    }

    T get(int i, int l, int r, int x, int y){
      propagate(i, l, r);
      if(r <= x or y <= l) return 0;
      if(x <= l and r <= y) return data[i];
      return
        get(i << 1 | 0, l, (l + r) / 2, x, y) +
        get(i << 1 | 1, (l + r) / 2, r, x, y);
    }

  public:
    void update(int l, int r, T a, T b){
      update(1, 0, hsize, l, r, a, b);
    }

    T get(int l, int r){
      return get(1, 0, hsize, l, r);
    }

    T operator[](int i){
      return get(i, i + 1);
    }
  };
}
