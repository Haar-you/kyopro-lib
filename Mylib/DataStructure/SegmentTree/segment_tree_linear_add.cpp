#pragma once
#include <vector>
#include <utility>

namespace haar_lib {
  template <typename T>
  class segment_tree_linear_add {
    using value_type = T;
    using P = std::pair<T, T>;

    int depth, size, hsize;

    std::vector<P> data;
    std::vector<int> from;

    P add(P a, P b){
      return {a.first + b.first, a.second + b.second};
    }

    void propagate(int i){
      if(i < hsize){
        data[i << 1 | 0] = add(data[i << 1 | 0], data[i]);

        int len = hsize >> (31 - __builtin_clz(i) + 1);
        data[i].first += data[i].second * len;
        data[i << 1 | 1] = add(data[i << 1 | 1], data[i]);

        data[i] = P();
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
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth), hsize(size / 2),
      data(size, P()),
      from(size)
    {
      int s = 0;
      for(int i = 1; i < size; ++i){
        from[i] = s;
        int l = hsize >> (31 - __builtin_clz(i));
        s += l;
        if(s == hsize) s = 0;
      }
    }

    void update(int l, int r, T a, T b){
      int L = l + hsize;
      int R = r + hsize;

      while(L < R){
        if(R & 1){
          --R;
          data[R] = add(std::make_pair(b + a * (from[R] - l), a), data[R]);
        }
        if(L & 1){
          data[L] = add(std::make_pair(b + a * (from[L] - l), a), data[L]);
          ++L;
        }
        L >>= 1;
        R >>= 1;
      }
    }

    T operator[](int i){
      propagate_top_down(i + hsize);
      return data[i + hsize].first;
    }

    std::vector<T> get_all(int n){
      std::vector<T> ret(n);
      for(int i = 1; i < hsize; ++i) propagate(i);
      for(int i = hsize; i < hsize + n; ++i) ret[i - hsize] = data[i].first;
      return ret;
    }
  };
}
