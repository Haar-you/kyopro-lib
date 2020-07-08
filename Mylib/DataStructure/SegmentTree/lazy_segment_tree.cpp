#pragma once
#include <vector>

/**
 * @title Lazy segment tree
 * @docs lazy_segment_tree.md
 */
template <typename Monoid>
class LazySegmentTree{
  using value_type_get = typename Monoid::value_type_get;
  using value_type_update = typename Monoid::value_type_update;
  
  const int depth, size, hsize;
  std::vector<value_type_get> data;
  std::vector<value_type_update> lazy;

  void propagate(int i){
    if(lazy[i] == Monoid::id_update()) return;
    if(i < hsize){
      lazy[i << 1 | 0] = Monoid::op_update(lazy[i], lazy[i << 1 | 0]);
      lazy[i << 1 | 1] = Monoid::op_update(lazy[i], lazy[i << 1 | 1]);
    }
    int len = hsize >> (31 - __builtin_clz(i));
    data[i] = Monoid::op(data[i], lazy[i], len);
    lazy[i] = Monoid::id_update();
  }

  value_type_get update_aux(int i, int l, int r, int s, int t, const value_type_update &x){
    propagate(i);
    if(r <= s || t <= l) return data[i];
    else if(s <= l && r <= t){
      lazy[i] = Monoid::op_update(x, lazy[i]);
      propagate(i);
      return data[i];
    }
    else return data[i] = Monoid::op_get(update_aux(i << 1 | 0, l, (l+r) / 2, s, t, x), update_aux(i << 1 | 1, (l+r) / 2, r, s, t, x));
  }
  
  value_type_get get_aux(int i, int l, int r, int x, int y){
    propagate(i);
    if(r <= x || y <= l) return Monoid::id_get();
    else if(x <= l && r <= y) return data[i];
    else return Monoid::op_get(get_aux(i << 1 | 0, l, (l+r) / 2, x, y), get_aux(i << 1 | 1, (l+r) / 2, r, x, y));
  }

public:
  LazySegmentTree(){}
  LazySegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),
    data(size, Monoid::id_get()),
    lazy(size, Monoid::id_update())
  {}

  void update(int l, int r, const value_type_update &x){update_aux(1, 0, hsize, l, r, x);}
  void update_at(int i, const value_type_update &x){update(i, i+1, x);}
  value_type_get get(int l, int r){return get_aux(1, 0, hsize, l, r);}
  value_type_get at(int i){return get(i, i+1);}

  template <typename T>
  void init(const T &val){
    init_with_vector(std::vector<T>(hsize, val));
  }

  template <typename T>
  void init_with_vector(const std::vector<T> &val){
    data.assign(size, Monoid::id_get());
    lazy.assign(size, Monoid::id_update());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i > 0; --i) data[i] = Monoid::op_get(data[i << 1 | 0], data[i << 1 | 1]);
  }
};
