#pragma once
#include <vector>

namespace haar_lib {
  template <typename T>
  class lazy_segment_tree_with_coefficients {
    const int depth, size, hsize;
    std::vector<T> data, lazy, coeff;

    void propagate(int i){
      if(lazy[i] == 0) return;
      if(i < hsize){
        lazy[i << 1 | 0] = lazy[i] + lazy[i << 1 | 0];
        lazy[i << 1 | 1] = lazy[i] + lazy[i << 1 | 1];
      }
      data[i] = data[i] + lazy[i] * coeff[i];
      lazy[i] = 0;
    }

    T update(int i, int l, int r, int s, int t, const T &x){
      propagate(i);
      if(r <= s || t <= l) return data[i];
      if(s <= l && r <= t){
        lazy[i] += x;
        propagate(i);
        return data[i];
      }
      return data[i] =
        update(i << 1 | 0, l, (l + r) / 2, s, t, x) +
        update(i << 1 | 1, (l + r) / 2, r, s, t, x);
    }

    T get(int i, int l, int r, int x, int y){
      propagate(i);
      if(r <= x || y <= l) return 0;
      if(x <= l && r <= y) return data[i];
      return get(i << 1 | 0, l, (l + r) / 2, x, y) + get(i << 1 | 1, (l + r) / 2, r, x, y);
    }

  public:
    lazy_segment_tree_with_coefficients(){}
    lazy_segment_tree_with_coefficients(int n, std::vector<T> coeff_):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth),
      hsize(size / 2),
      data(size, 0),
      lazy(size, 0),
      coeff(size, 0)
    {
      for(int i = hsize; i < size; ++i) coeff[i] = coeff_[i - hsize];
      for(int i = hsize; --i >= 1;) coeff[i] = coeff[i << 1 | 0] + coeff[i << 1 | 1];
    }

    void update(int l, int r, const T &x){update(1, 0, hsize, l, r, x);}
    void update(int i, const T &x){update(i, i + 1, x);}
    T fold(int l, int r){return get(1, 0, hsize, l, r);}
    T operator[](int i){return fold(i, i + 1);}

    void init(const T &val){
      init_with_vector(std::vector<T>(hsize, val));
    }

    void init_with_vector(const std::vector<T> &val){
      data.assign(size, 0);
      lazy.assign(size, 0);
      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
      for(int i = hsize; --i >= 0;) data[i] = data[i << 1 | 0] + data[i << 1 | 1];
    }
  };
}
