#pragma once
#include <vector>
#include <limits>
#include <algorithm>

/**
 * @title Segment tree beats
 * @see https://judge.yosupo.jp/submission/5293 (chmin, chmax, add, sum)
 */
class SegmentTreeBeats{
  using value_type = int64_t;

  const int depth, size, hsize;

  std::vector<value_type> fst_max, snd_max;
  std::vector<int> max_count;

  std::vector<value_type> fst_min, snd_min;
  std::vector<int> min_count;
  
  std::vector<value_type> sum, lazy_add;

public:
  SegmentTreeBeats(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),

    fst_max(size, std::numeric_limits<value_type>::min()),
    snd_max(size, std::numeric_limits<value_type>::min()),
    max_count(size, 0),

    fst_min(size, std::numeric_limits<value_type>::max()),
    snd_min(size, std::numeric_limits<value_type>::max()),
    min_count(size, 0),
    
    sum(size, 0),
    lazy_add(size, 0)
  {}

private:
  inline int lc(int i) const {return i << 1 | 0;} // left child
  inline int rc(int i) const {return i << 1 | 1;} // right child
  
  inline void update_node_max(int i, value_type x){
    sum[i] += (x - fst_max[i]) * max_count[i];

    if(fst_max[i] == fst_min[i]) fst_max[i] = fst_min[i] = x;
    else if(fst_max[i] == snd_min[i]) fst_max[i] = snd_min[i] = x;
    else fst_max[i] = x;
  }

  inline void update_node_min(int i, value_type x){
    sum[i] += (x - fst_min[i]) * min_count[i];

    if(fst_max[i] == fst_min[i]) fst_max[i] = fst_min[i] = x;
    else if(snd_max[i] == fst_min[i]) snd_max[i] = fst_min[i] = x;
    else fst_min[i] = x;
  }

  inline void update_node_add(int i, value_type x){
    const int len = hsize >> (31 - __builtin_clz(i));

    sum[i] += x * len;
    fst_max[i] += x;
    if(snd_max[i] != std::numeric_limits<value_type>::min()) snd_max[i] += x;
    fst_min[i] += x;
    if(snd_min[i] != std::numeric_limits<value_type>::max()) snd_min[i] += x;

    lazy_add[i] += x;
  }
  
  inline void propagate(int i){
    if(i >= hsize) return;

    if(lazy_add[i] != 0){
      update_node_add(lc(i), lazy_add[i]);
      update_node_add(rc(i), lazy_add[i]);
      lazy_add[i] = 0;
    }

    if(fst_max[i] < fst_max[lc(i)]) update_node_max(lc(i), fst_max[i]);
    if(fst_min[i] > fst_min[lc(i)]) update_node_min(lc(i), fst_min[i]);

    if(fst_max[i] < fst_max[rc(i)]) update_node_max(rc(i), fst_max[i]);
    if(fst_min[i] > fst_min[rc(i)]) update_node_min(rc(i), fst_min[i]);
  }

  inline void bottom_up(int i){
    const int L = lc(i);
    const int R = rc(i);
    
    sum[i] = sum[L] + sum[R];

    fst_max[i] = std::max(fst_max[L], fst_max[R]);
    
    if(fst_max[L] < fst_max[R]){
      max_count[i] = max_count[R];
      snd_max[i] = std::max(fst_max[L], snd_max[R]);
    }else if(fst_max[L] > fst_max[R]){
      max_count[i] = max_count[L];
      snd_max[i] = std::max(snd_max[L], fst_max[R]);
    }else{
      max_count[i] = max_count[L] + max_count[R];
      snd_max[i] = std::max(snd_max[L], snd_max[R]);
    }

    fst_min[i] = std::min(fst_min[L], fst_min[R]);
    
    if(fst_min[L] > fst_min[R]){
      min_count[i] = min_count[R];
      snd_min[i] = std::min(fst_min[L], snd_min[R]);
    }else if(fst_min[L] < fst_min[R]){
      min_count[i] = min_count[L];
      snd_min[i] = std::min(snd_min[L], fst_min[R]);
    }else{
      min_count[i] = min_count[L] + min_count[R];
      snd_min[i] = std::min(snd_min[L], snd_min[R]);
    }
  }
  
private:
  void chmin(int i, int l, int r, int s, int t, value_type x){
    if(r <= s or t <= l or fst_max[i] <= x) return;
    if(s <= l and r <= t and snd_max[i] < x){
      update_node_max(i, x);
      return;
    }

    propagate(i);    
    chmin(lc(i), l, (l + r) / 2, s, t, x);
    chmin(rc(i), (l + r) / 2, r, s, t, x);
    bottom_up(i);
  }

public:
  void chmin(int l, int r, value_type x){chmin(1, 0, hsize, l, r, x);}

private:
  void chmax(int i, int l, int r, int s, int t, value_type x){
    if(r <= s or t <= l or fst_min[i] >= x) return;
    if(s <= l and r <= t and snd_min[i] > x){
      update_node_min(i, x);
      return;
    }

    propagate(i);
    chmax(lc(i), l, (l + r) / 2, s, t, x);
    chmax(rc(i), (l + r) / 2, r, s, t, x);
    bottom_up(i);
  }

public:
  void chmax(int l, int r, value_type x){chmax(1, 0, hsize, l, r, x);}

private:
  void add(int i, int l, int r, int s, int t, value_type x){
    if(r <= s or t <= l) return;
    if(s <= l and r <= t){
      update_node_add(i, x);
      return;
    }

    propagate(i);
    add(lc(i), l, (l + r) / 2, s, t, x);
    add(rc(i), (l + r) / 2, r, s, t, x);
    bottom_up(i);
  }

public:
  void add(int l, int r, value_type x){add(1, 0, hsize, l, r, x);}
  
private:
  value_type get_sum(int i, int l, int r, int s, int t){
    if(r <= s or t <= l) return 0;
    if(s <= l and r <= t) return sum[i];

    propagate(i);
    return get_sum(lc(i), l, (l + r) / 2, s, t) + get_sum(rc(i), (l + r) / 2, r, s, t);
  }

public:
  value_type get_sum(int l, int r){return get_sum(1, 0, hsize, l, r);}


public:  
  void init_with_vector(const std::vector<value_type> &v){
    fst_max.assign(size, std::numeric_limits<value_type>::min());
    snd_max.assign(size, std::numeric_limits<value_type>::min());
    max_count.assign(size, 1);

    fst_min.assign(size, std::numeric_limits<value_type>::max());
    snd_min.assign(size, std::numeric_limits<value_type>::max());
    min_count.assign(size, 1);
    
    sum.assign(size, 0);
    lazy_add.assign(size, 0);

    for(int i = 0; i < (int)v.size(); ++i){
      fst_max[hsize + i] = v[i];
      max_count[hsize + i] = 1;
      fst_min[hsize + i] = v[i];
      min_count[hsize + i] = 1;
      sum[hsize + i] = v[i];
    }

    for(int i = hsize - 1; i > 0; --i) bottom_up(i);
  }
};
