#pragma once
#include <vector>

namespace haar_lib {
  template <typename Monoid>
  class lazy_segment_tree {
    using value_type_get = typename Monoid::value_type_get;
    using value_type_update = typename Monoid::value_type_update;
    const static Monoid M;

    const int depth, size, hsize;
    std::vector<value_type_get> data;
    std::vector<value_type_update> lazy;

    void propagate(int i){
      if(lazy[i] == M.id_update()) return;
      if(i < hsize){
        lazy[i << 1 | 0] = M.op_update(lazy[i], lazy[i << 1 | 0]);
        lazy[i << 1 | 1] = M.op_update(lazy[i], lazy[i << 1 | 1]);
      }
      int len = hsize >> (31 - __builtin_clz(i));
      data[i] = M.op(data[i], lazy[i], len);
      lazy[i] = M.id_update();
    }

    void propagate_top_down(int i){
      std::vector<int> temp;
      while(i > 1){
        i >>= 1;
        temp.push_back(i);
      }

      for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);
    }

    void bottom_up(int i){
      while(i > 1){
        i >>= 1;
        propagate(i << 1 | 0);
        propagate(i << 1 | 1);
        data[i] = M.op_get(data[i << 1 | 0], data[i << 1 | 1]);
      }
    }

  public:
    lazy_segment_tree(){}
    lazy_segment_tree(int n):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth),
      hsize(size / 2),
      data(size, M.id_get()),
      lazy(size, M.id_update())
    {}

    void update(int l, int r, const value_type_update &x){
      propagate_top_down(l + hsize);
      if(r < hsize) propagate_top_down(r + hsize);

      int L = l + hsize, R = r + hsize;

      while(L < R){
        if(R & 1){
          --R;
          lazy[R] = M.op_update(x, lazy[R]);
          propagate(R);
        }
        if(L & 1){
          lazy[L] = M.op_update(x, lazy[L]);
          propagate(L);
          ++L;
        }
        L >>= 1;
        R >>= 1;
      }

      bottom_up(l + hsize);
      if(r < hsize) bottom_up(r + hsize);
    }

    void update_at(int i, const value_type_update &x){update(i, i + 1, x);}

    value_type_get get(int l, int r){
      propagate_top_down(l + hsize);
      if(r < hsize) propagate_top_down(r + hsize);

      value_type_get ret_left = M.id_get(), ret_right = M.id_get();

      int L = l + hsize, R = r + hsize;

      while(L < R){
        if(R & 1){
          --R;
          propagate(R);
          ret_right = M.op_get(data[R], ret_right);
        }
        if(L & 1){
          propagate(L);
          ret_left = M.op_get(ret_left, data[L]);
          ++L;
        }
        L >>= 1;
        R >>= 1;
      }

      return M.op_get(ret_left, ret_right);
    }

    value_type_get operator[](int i){return get(i, i + 1);}

    template <typename T>
    void init(const T &val){
      init_with_vector(std::vector<T>(hsize, val));
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &val){
      data.assign(size, M.id_get());
      lazy.assign(size, M.id_update());
      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
      for(int i = hsize - 1; i > 0; --i) data[i] = M.op_get(data[i << 1 | 0], data[i << 1 | 1]);
    }
  };
}
