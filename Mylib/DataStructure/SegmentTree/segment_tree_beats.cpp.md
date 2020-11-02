---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp
    title: test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp\"\
    \n#include <vector>\n#include <limits>\n#include <algorithm>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  class segment_tree_beats {\n  public:\n    using value_type\
    \ = int64_t;\n\n  private:\n    int depth_, size_, hsize_;\n\n    std::vector<value_type>\
    \ fst_max_, snd_max_;\n    std::vector<int> max_count_;\n\n    std::vector<value_type>\
    \ fst_min_, snd_min_;\n    std::vector<int> min_count_;\n\n    std::vector<value_type>\
    \ sum_, lazy_add_;\n\n  public:\n    segment_tree_beats(){}\n    segment_tree_beats(int\
    \ n):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1\
    \ << depth_),\n      hsize_(size_ / 2),\n\n      fst_max_(size_, std::numeric_limits<value_type>::min()),\n\
    \      snd_max_(size_, std::numeric_limits<value_type>::min()),\n      max_count_(size_,\
    \ 0),\n\n      fst_min_(size_, std::numeric_limits<value_type>::max()),\n    \
    \  snd_min_(size_, std::numeric_limits<value_type>::max()),\n      min_count_(size_,\
    \ 0),\n\n      sum_(size_, 0),\n      lazy_add_(size_, 0)\n    {}\n\n  private:\n\
    \    int lc(int i) const {return i << 1 | 0;} // left child\n    int rc(int i)\
    \ const {return i << 1 | 1;} // right child\n\n    void update_node_max(int i,\
    \ value_type x){\n      sum_[i] += (x - fst_max_[i]) * max_count_[i];\n\n    \
    \  if(fst_max_[i] == fst_min_[i]) fst_max_[i] = fst_min_[i] = x;\n      else if(fst_max_[i]\
    \ == snd_min_[i]) fst_max_[i] = snd_min_[i] = x;\n      else fst_max_[i] = x;\n\
    \    }\n\n    void update_node_min(int i, value_type x){\n      sum_[i] += (x\
    \ - fst_min_[i]) * min_count_[i];\n\n      if(fst_max_[i] == fst_min_[i]) fst_max_[i]\
    \ = fst_min_[i] = x;\n      else if(snd_max_[i] == fst_min_[i]) snd_max_[i] =\
    \ fst_min_[i] = x;\n      else fst_min_[i] = x;\n    }\n\n    void update_node_add(int\
    \ i, value_type x){\n      const int len = hsize_ >> (31 - __builtin_clz(i));\n\
    \n      sum_[i] += x * len;\n      fst_max_[i] += x;\n      if(snd_max_[i] !=\
    \ std::numeric_limits<value_type>::min()) snd_max_[i] += x;\n      fst_min_[i]\
    \ += x;\n      if(snd_min_[i] != std::numeric_limits<value_type>::max()) snd_min_[i]\
    \ += x;\n\n      lazy_add_[i] += x;\n    }\n\n    void propagate(int i){\n   \
    \   if(i >= hsize_) return;\n\n      if(lazy_add_[i] != 0){\n        update_node_add(lc(i),\
    \ lazy_add_[i]);\n        update_node_add(rc(i), lazy_add_[i]);\n        lazy_add_[i]\
    \ = 0;\n      }\n\n      if(fst_max_[i] < fst_max_[lc(i)]) update_node_max(lc(i),\
    \ fst_max_[i]);\n      if(fst_min_[i] > fst_min_[lc(i)]) update_node_min(lc(i),\
    \ fst_min_[i]);\n\n      if(fst_max_[i] < fst_max_[rc(i)]) update_node_max(rc(i),\
    \ fst_max_[i]);\n      if(fst_min_[i] > fst_min_[rc(i)]) update_node_min(rc(i),\
    \ fst_min_[i]);\n    }\n\n    void bottom_up(int i){\n      const int L = lc(i);\n\
    \      const int R = rc(i);\n\n      sum_[i] = sum_[L] + sum_[R];\n\n      fst_max_[i]\
    \ = std::max(fst_max_[L], fst_max_[R]);\n\n      if(fst_max_[L] < fst_max_[R]){\n\
    \        max_count_[i] = max_count_[R];\n        snd_max_[i] = std::max(fst_max_[L],\
    \ snd_max_[R]);\n      }else if(fst_max_[L] > fst_max_[R]){\n        max_count_[i]\
    \ = max_count_[L];\n        snd_max_[i] = std::max(snd_max_[L], fst_max_[R]);\n\
    \      }else{\n        max_count_[i] = max_count_[L] + max_count_[R];\n      \
    \  snd_max_[i] = std::max(snd_max_[L], snd_max_[R]);\n      }\n\n      fst_min_[i]\
    \ = std::min(fst_min_[L], fst_min_[R]);\n\n      if(fst_min_[L] > fst_min_[R]){\n\
    \        min_count_[i] = min_count_[R];\n        snd_min_[i] = std::min(fst_min_[L],\
    \ snd_min_[R]);\n      }else if(fst_min_[L] < fst_min_[R]){\n        min_count_[i]\
    \ = min_count_[L];\n        snd_min_[i] = std::min(snd_min_[L], fst_min_[R]);\n\
    \      }else{\n        min_count_[i] = min_count_[L] + min_count_[R];\n      \
    \  snd_min_[i] = std::min(snd_min_[L], snd_min_[R]);\n      }\n    }\n\n  private:\n\
    \    void chmin(int i, int l, int r, int s, int t, value_type x){\n      if(r\
    \ <= s or t <= l or fst_max_[i] <= x) return;\n      if(s <= l and r <= t and\
    \ snd_max_[i] < x){\n        update_node_max(i, x);\n        return;\n      }\n\
    \n      propagate(i);\n      chmin(lc(i), l, (l + r) / 2, s, t, x);\n      chmin(rc(i),\
    \ (l + r) / 2, r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n    void\
    \ chmin(int l, int r, value_type x){\n      assert(0 <= l and l <= r and r <=\
    \ hsize_);\n      chmin(1, 0, hsize_, l, r, x);\n    }\n\n  private:\n    void\
    \ chmax(int i, int l, int r, int s, int t, value_type x){\n      if(r <= s or\
    \ t <= l or fst_min_[i] >= x) return;\n      if(s <= l and r <= t and snd_min_[i]\
    \ > x){\n        update_node_min(i, x);\n        return;\n      }\n\n      propagate(i);\n\
    \      chmax(lc(i), l, (l + r) / 2, s, t, x);\n      chmax(rc(i), (l + r) / 2,\
    \ r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n    void chmax(int l,\
    \ int r, value_type x){\n      assert(0 <= l and l <= r and r <= hsize_);\n  \
    \    chmax(1, 0, hsize_, l, r, x);\n    }\n\n  private:\n    void add(int i, int\
    \ l, int r, int s, int t, value_type x){\n      if(r <= s or t <= l) return;\n\
    \      if(s <= l and r <= t){\n        update_node_add(i, x);\n        return;\n\
    \      }\n\n      propagate(i);\n      add(lc(i), l, (l + r) / 2, s, t, x);\n\
    \      add(rc(i), (l + r) / 2, r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n\
    \    void add(int l, int r, value_type x){\n      assert(0 <= l and l <= r and\
    \ r <= hsize_);\n      add(1, 0, hsize_, l, r, x);\n    }\n\n  private:\n    value_type\
    \ get_sum(int i, int l, int r, int s, int t){\n      if(r <= s or t <= l) return\
    \ 0;\n      if(s <= l and r <= t) return sum_[i];\n\n      propagate(i);\n   \
    \   return get_sum(lc(i), l, (l + r) / 2, s, t) + get_sum(rc(i), (l + r) / 2,\
    \ r, s, t);\n    }\n\n  public:\n    value_type get_sum(int l, int r){\n     \
    \ assert(0 <= l and l <= r and r <= hsize_);\n      return get_sum(1, 0, hsize_,\
    \ l, r);\n    }\n\n  public:\n    void init_with_vector(const std::vector<value_type>\
    \ &v){\n      fst_max_.assign(size_, std::numeric_limits<value_type>::min());\n\
    \      snd_max_.assign(size_, std::numeric_limits<value_type>::min());\n     \
    \ max_count_.assign(size_, 1);\n\n      fst_min_.assign(size_, std::numeric_limits<value_type>::max());\n\
    \      snd_min_.assign(size_, std::numeric_limits<value_type>::max());\n     \
    \ min_count_.assign(size_, 1);\n\n      sum_.assign(size_, 0);\n      lazy_add_.assign(size_,\
    \ 0);\n\n      for(int i = 0; i < (int)v.size(); ++i){\n        fst_max_[hsize_\
    \ + i] = v[i];\n        max_count_[hsize_ + i] = 1;\n        fst_min_[hsize_ +\
    \ i] = v[i];\n        min_count_[hsize_ + i] = 1;\n        sum_[hsize_ + i] =\
    \ v[i];\n      }\n\n      for(int i = hsize_; --i >= 1;) bottom_up(i);\n    }\n\
    \  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <limits>\n#include <algorithm>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  class segment_tree_beats {\n  public:\n\
    \    using value_type = int64_t;\n\n  private:\n    int depth_, size_, hsize_;\n\
    \n    std::vector<value_type> fst_max_, snd_max_;\n    std::vector<int> max_count_;\n\
    \n    std::vector<value_type> fst_min_, snd_min_;\n    std::vector<int> min_count_;\n\
    \n    std::vector<value_type> sum_, lazy_add_;\n\n  public:\n    segment_tree_beats(){}\n\
    \    segment_tree_beats(int n):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1)\
    \ + 1 : 1),\n      size_(1 << depth_),\n      hsize_(size_ / 2),\n\n      fst_max_(size_,\
    \ std::numeric_limits<value_type>::min()),\n      snd_max_(size_, std::numeric_limits<value_type>::min()),\n\
    \      max_count_(size_, 0),\n\n      fst_min_(size_, std::numeric_limits<value_type>::max()),\n\
    \      snd_min_(size_, std::numeric_limits<value_type>::max()),\n      min_count_(size_,\
    \ 0),\n\n      sum_(size_, 0),\n      lazy_add_(size_, 0)\n    {}\n\n  private:\n\
    \    int lc(int i) const {return i << 1 | 0;} // left child\n    int rc(int i)\
    \ const {return i << 1 | 1;} // right child\n\n    void update_node_max(int i,\
    \ value_type x){\n      sum_[i] += (x - fst_max_[i]) * max_count_[i];\n\n    \
    \  if(fst_max_[i] == fst_min_[i]) fst_max_[i] = fst_min_[i] = x;\n      else if(fst_max_[i]\
    \ == snd_min_[i]) fst_max_[i] = snd_min_[i] = x;\n      else fst_max_[i] = x;\n\
    \    }\n\n    void update_node_min(int i, value_type x){\n      sum_[i] += (x\
    \ - fst_min_[i]) * min_count_[i];\n\n      if(fst_max_[i] == fst_min_[i]) fst_max_[i]\
    \ = fst_min_[i] = x;\n      else if(snd_max_[i] == fst_min_[i]) snd_max_[i] =\
    \ fst_min_[i] = x;\n      else fst_min_[i] = x;\n    }\n\n    void update_node_add(int\
    \ i, value_type x){\n      const int len = hsize_ >> (31 - __builtin_clz(i));\n\
    \n      sum_[i] += x * len;\n      fst_max_[i] += x;\n      if(snd_max_[i] !=\
    \ std::numeric_limits<value_type>::min()) snd_max_[i] += x;\n      fst_min_[i]\
    \ += x;\n      if(snd_min_[i] != std::numeric_limits<value_type>::max()) snd_min_[i]\
    \ += x;\n\n      lazy_add_[i] += x;\n    }\n\n    void propagate(int i){\n   \
    \   if(i >= hsize_) return;\n\n      if(lazy_add_[i] != 0){\n        update_node_add(lc(i),\
    \ lazy_add_[i]);\n        update_node_add(rc(i), lazy_add_[i]);\n        lazy_add_[i]\
    \ = 0;\n      }\n\n      if(fst_max_[i] < fst_max_[lc(i)]) update_node_max(lc(i),\
    \ fst_max_[i]);\n      if(fst_min_[i] > fst_min_[lc(i)]) update_node_min(lc(i),\
    \ fst_min_[i]);\n\n      if(fst_max_[i] < fst_max_[rc(i)]) update_node_max(rc(i),\
    \ fst_max_[i]);\n      if(fst_min_[i] > fst_min_[rc(i)]) update_node_min(rc(i),\
    \ fst_min_[i]);\n    }\n\n    void bottom_up(int i){\n      const int L = lc(i);\n\
    \      const int R = rc(i);\n\n      sum_[i] = sum_[L] + sum_[R];\n\n      fst_max_[i]\
    \ = std::max(fst_max_[L], fst_max_[R]);\n\n      if(fst_max_[L] < fst_max_[R]){\n\
    \        max_count_[i] = max_count_[R];\n        snd_max_[i] = std::max(fst_max_[L],\
    \ snd_max_[R]);\n      }else if(fst_max_[L] > fst_max_[R]){\n        max_count_[i]\
    \ = max_count_[L];\n        snd_max_[i] = std::max(snd_max_[L], fst_max_[R]);\n\
    \      }else{\n        max_count_[i] = max_count_[L] + max_count_[R];\n      \
    \  snd_max_[i] = std::max(snd_max_[L], snd_max_[R]);\n      }\n\n      fst_min_[i]\
    \ = std::min(fst_min_[L], fst_min_[R]);\n\n      if(fst_min_[L] > fst_min_[R]){\n\
    \        min_count_[i] = min_count_[R];\n        snd_min_[i] = std::min(fst_min_[L],\
    \ snd_min_[R]);\n      }else if(fst_min_[L] < fst_min_[R]){\n        min_count_[i]\
    \ = min_count_[L];\n        snd_min_[i] = std::min(snd_min_[L], fst_min_[R]);\n\
    \      }else{\n        min_count_[i] = min_count_[L] + min_count_[R];\n      \
    \  snd_min_[i] = std::min(snd_min_[L], snd_min_[R]);\n      }\n    }\n\n  private:\n\
    \    void chmin(int i, int l, int r, int s, int t, value_type x){\n      if(r\
    \ <= s or t <= l or fst_max_[i] <= x) return;\n      if(s <= l and r <= t and\
    \ snd_max_[i] < x){\n        update_node_max(i, x);\n        return;\n      }\n\
    \n      propagate(i);\n      chmin(lc(i), l, (l + r) / 2, s, t, x);\n      chmin(rc(i),\
    \ (l + r) / 2, r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n    void\
    \ chmin(int l, int r, value_type x){\n      assert(0 <= l and l <= r and r <=\
    \ hsize_);\n      chmin(1, 0, hsize_, l, r, x);\n    }\n\n  private:\n    void\
    \ chmax(int i, int l, int r, int s, int t, value_type x){\n      if(r <= s or\
    \ t <= l or fst_min_[i] >= x) return;\n      if(s <= l and r <= t and snd_min_[i]\
    \ > x){\n        update_node_min(i, x);\n        return;\n      }\n\n      propagate(i);\n\
    \      chmax(lc(i), l, (l + r) / 2, s, t, x);\n      chmax(rc(i), (l + r) / 2,\
    \ r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n    void chmax(int l,\
    \ int r, value_type x){\n      assert(0 <= l and l <= r and r <= hsize_);\n  \
    \    chmax(1, 0, hsize_, l, r, x);\n    }\n\n  private:\n    void add(int i, int\
    \ l, int r, int s, int t, value_type x){\n      if(r <= s or t <= l) return;\n\
    \      if(s <= l and r <= t){\n        update_node_add(i, x);\n        return;\n\
    \      }\n\n      propagate(i);\n      add(lc(i), l, (l + r) / 2, s, t, x);\n\
    \      add(rc(i), (l + r) / 2, r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n\
    \    void add(int l, int r, value_type x){\n      assert(0 <= l and l <= r and\
    \ r <= hsize_);\n      add(1, 0, hsize_, l, r, x);\n    }\n\n  private:\n    value_type\
    \ get_sum(int i, int l, int r, int s, int t){\n      if(r <= s or t <= l) return\
    \ 0;\n      if(s <= l and r <= t) return sum_[i];\n\n      propagate(i);\n   \
    \   return get_sum(lc(i), l, (l + r) / 2, s, t) + get_sum(rc(i), (l + r) / 2,\
    \ r, s, t);\n    }\n\n  public:\n    value_type get_sum(int l, int r){\n     \
    \ assert(0 <= l and l <= r and r <= hsize_);\n      return get_sum(1, 0, hsize_,\
    \ l, r);\n    }\n\n  public:\n    void init_with_vector(const std::vector<value_type>\
    \ &v){\n      fst_max_.assign(size_, std::numeric_limits<value_type>::min());\n\
    \      snd_max_.assign(size_, std::numeric_limits<value_type>::min());\n     \
    \ max_count_.assign(size_, 1);\n\n      fst_min_.assign(size_, std::numeric_limits<value_type>::max());\n\
    \      snd_min_.assign(size_, std::numeric_limits<value_type>::max());\n     \
    \ min_count_.assign(size_, 1);\n\n      sum_.assign(size_, 0);\n      lazy_add_.assign(size_,\
    \ 0);\n\n      for(int i = 0; i < (int)v.size(); ++i){\n        fst_max_[hsize_\
    \ + i] = v[i];\n        max_count_[hsize_ + i] = 1;\n        fst_min_[hsize_ +\
    \ i] = v[i];\n        min_count_[hsize_ + i] = 1;\n        sum_[hsize_ + i] =\
    \ v[i];\n      }\n\n      for(int i = hsize_; --i >= 1;) bottom_up(i);\n    }\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp
layout: document
title: Segment tree beats
---

## Operations

- `SegmentTreeBeats(n)`
- `chmin(l, r, v)`
	- `i in [l, r)`について$a_i \leftarrow \min(a_i, v)$で更新。
- `chmax(l, r, v)`
	- `i in [l, r)`について$a_i \leftarrow \max(a_i, v)$で更新。
- `add(l, r, v)`
	- `i in [l, r)`について$a_i \leftarrow a_i + v$で更新。
- `get_sum(l, r)`
	- $\sum_{l \le i \lt r} a_i$を返す。
- `init_with_vector(a)`

## Requirements

## Notes

## Problems

- [Range Chmin Chmax Add Range Sum](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum)

## References

- [https://codeforces.com/blog/entry/57319](https://codeforces.com/blog/entry/57319)
- [https://smijake3.hatenablog.com/entry/2019/04/28/021457](https://smijake3.hatenablog.com/entry/2019/04/28/021457)

