#pragma once
#include <vector>
#include <limits>
#include <algorithm>
#include <cassert>

namespace haar_lib {
  class segment_tree_beats {
  public:
    using value_type = int64_t;

  private:
    int depth_, size_, hsize_;

    std::vector<value_type> fst_max_, snd_max_;
    std::vector<int> max_count_;

    std::vector<value_type> fst_min_, snd_min_;
    std::vector<int> min_count_;

    std::vector<value_type> sum_, lazy_add_;

  public:
    segment_tree_beats(){}
    segment_tree_beats(int n):
      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size_(1 << depth_),
      hsize_(size_ / 2),

      fst_max_(size_, std::numeric_limits<value_type>::min()),
      snd_max_(size_, std::numeric_limits<value_type>::min()),
      max_count_(size_, 0),

      fst_min_(size_, std::numeric_limits<value_type>::max()),
      snd_min_(size_, std::numeric_limits<value_type>::max()),
      min_count_(size_, 0),

      sum_(size_, 0),
      lazy_add_(size_, 0)
    {}

  private:
    int lc(int i) const {return i << 1 | 0;} // left child
    int rc(int i) const {return i << 1 | 1;} // right child

    void update_node_max(int i, value_type x){
      sum_[i] += (x - fst_max_[i]) * max_count_[i];

      if(fst_max_[i] == fst_min_[i]) fst_max_[i] = fst_min_[i] = x;
      else if(fst_max_[i] == snd_min_[i]) fst_max_[i] = snd_min_[i] = x;
      else fst_max_[i] = x;
    }

    void update_node_min(int i, value_type x){
      sum_[i] += (x - fst_min_[i]) * min_count_[i];

      if(fst_max_[i] == fst_min_[i]) fst_max_[i] = fst_min_[i] = x;
      else if(snd_max_[i] == fst_min_[i]) snd_max_[i] = fst_min_[i] = x;
      else fst_min_[i] = x;
    }

    void update_node_add(int i, value_type x){
      const int len = hsize_ >> (31 - __builtin_clz(i));

      sum_[i] += x * len;
      fst_max_[i] += x;
      if(snd_max_[i] != std::numeric_limits<value_type>::min()) snd_max_[i] += x;
      fst_min_[i] += x;
      if(snd_min_[i] != std::numeric_limits<value_type>::max()) snd_min_[i] += x;

      lazy_add_[i] += x;
    }

    void propagate(int i){
      if(i >= hsize_) return;

      if(lazy_add_[i] != 0){
        update_node_add(lc(i), lazy_add_[i]);
        update_node_add(rc(i), lazy_add_[i]);
        lazy_add_[i] = 0;
      }

      if(fst_max_[i] < fst_max_[lc(i)]) update_node_max(lc(i), fst_max_[i]);
      if(fst_min_[i] > fst_min_[lc(i)]) update_node_min(lc(i), fst_min_[i]);

      if(fst_max_[i] < fst_max_[rc(i)]) update_node_max(rc(i), fst_max_[i]);
      if(fst_min_[i] > fst_min_[rc(i)]) update_node_min(rc(i), fst_min_[i]);
    }

    void bottom_up(int i){
      const int L = lc(i);
      const int R = rc(i);

      sum_[i] = sum_[L] + sum_[R];

      fst_max_[i] = std::max(fst_max_[L], fst_max_[R]);

      if(fst_max_[L] < fst_max_[R]){
        max_count_[i] = max_count_[R];
        snd_max_[i] = std::max(fst_max_[L], snd_max_[R]);
      }else if(fst_max_[L] > fst_max_[R]){
        max_count_[i] = max_count_[L];
        snd_max_[i] = std::max(snd_max_[L], fst_max_[R]);
      }else{
        max_count_[i] = max_count_[L] + max_count_[R];
        snd_max_[i] = std::max(snd_max_[L], snd_max_[R]);
      }

      fst_min_[i] = std::min(fst_min_[L], fst_min_[R]);

      if(fst_min_[L] > fst_min_[R]){
        min_count_[i] = min_count_[R];
        snd_min_[i] = std::min(fst_min_[L], snd_min_[R]);
      }else if(fst_min_[L] < fst_min_[R]){
        min_count_[i] = min_count_[L];
        snd_min_[i] = std::min(snd_min_[L], fst_min_[R]);
      }else{
        min_count_[i] = min_count_[L] + min_count_[R];
        snd_min_[i] = std::min(snd_min_[L], snd_min_[R]);
      }
    }

  private:
    void chmin(int i, int l, int r, int s, int t, value_type x){
      if(r <= s or t <= l or fst_max_[i] <= x) return;
      if(s <= l and r <= t and snd_max_[i] < x){
        update_node_max(i, x);
        return;
      }

      propagate(i);
      chmin(lc(i), l, (l + r) / 2, s, t, x);
      chmin(rc(i), (l + r) / 2, r, s, t, x);
      bottom_up(i);
    }

  public:
    void chmin(int l, int r, value_type x){
      assert(0 <= l and l <= r and r <= hsize_);
      chmin(1, 0, hsize_, l, r, x);
    }

  private:
    void chmax(int i, int l, int r, int s, int t, value_type x){
      if(r <= s or t <= l or fst_min_[i] >= x) return;
      if(s <= l and r <= t and snd_min_[i] > x){
        update_node_min(i, x);
        return;
      }

      propagate(i);
      chmax(lc(i), l, (l + r) / 2, s, t, x);
      chmax(rc(i), (l + r) / 2, r, s, t, x);
      bottom_up(i);
    }

  public:
    void chmax(int l, int r, value_type x){
      assert(0 <= l and l <= r and r <= hsize_);
      chmax(1, 0, hsize_, l, r, x);
    }

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
    void add(int l, int r, value_type x){
      assert(0 <= l and l <= r and r <= hsize_);
      add(1, 0, hsize_, l, r, x);
    }

  private:
    value_type get_sum(int i, int l, int r, int s, int t){
      if(r <= s or t <= l) return 0;
      if(s <= l and r <= t) return sum_[i];

      propagate(i);
      return get_sum(lc(i), l, (l + r) / 2, s, t) + get_sum(rc(i), (l + r) / 2, r, s, t);
    }

  public:
    value_type get_sum(int l, int r){
      assert(0 <= l and l <= r and r <= hsize_);
      return get_sum(1, 0, hsize_, l, r);
    }

  public:
    void init_with_vector(const std::vector<value_type> &v){
      fst_max_.assign(size_, std::numeric_limits<value_type>::min());
      snd_max_.assign(size_, std::numeric_limits<value_type>::min());
      max_count_.assign(size_, 1);

      fst_min_.assign(size_, std::numeric_limits<value_type>::max());
      snd_min_.assign(size_, std::numeric_limits<value_type>::max());
      min_count_.assign(size_, 1);

      sum_.assign(size_, 0);
      lazy_add_.assign(size_, 0);

      for(int i = 0; i < (int)v.size(); ++i){
        fst_max_[hsize_ + i] = v[i];
        max_count_[hsize_ + i] = 1;
        fst_min_[hsize_ + i] = v[i];
        min_count_[hsize_ + i] = 1;
        sum_[hsize_ + i] = v[i];
      }

      for(int i = hsize_; --i >= 1;) bottom_up(i);
    }
  };
}
