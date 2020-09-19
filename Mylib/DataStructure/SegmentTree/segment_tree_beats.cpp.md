---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp
    title: test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp\"\
    \n#include <vector>\n#include <limits>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  class segment_tree_beats {\n    using value_type = int64_t;\n\n    const\
    \ int depth, size, hsize;\n\n    std::vector<value_type> fst_max, snd_max;\n \
    \   std::vector<int> max_count;\n\n    std::vector<value_type> fst_min, snd_min;\n\
    \    std::vector<int> min_count;\n\n    std::vector<value_type> sum, lazy_add;\n\
    \n  public:\n    segment_tree_beats(int n):\n      depth(n > 1 ? 32 - __builtin_clz(n\
    \ - 1) + 1 : 1),\n      size(1 << depth),\n      hsize(size / 2),\n\n      fst_max(size,\
    \ std::numeric_limits<value_type>::min()),\n      snd_max(size, std::numeric_limits<value_type>::min()),\n\
    \      max_count(size, 0),\n\n      fst_min(size, std::numeric_limits<value_type>::max()),\n\
    \      snd_min(size, std::numeric_limits<value_type>::max()),\n      min_count(size,\
    \ 0),\n\n      sum(size, 0),\n      lazy_add(size, 0)\n    {}\n\n  private:\n\
    \    int lc(int i) const {return i << 1 | 0;} // left child\n    int rc(int i)\
    \ const {return i << 1 | 1;} // right child\n\n    void update_node_max(int i,\
    \ value_type x){\n      sum[i] += (x - fst_max[i]) * max_count[i];\n\n      if(fst_max[i]\
    \ == fst_min[i]) fst_max[i] = fst_min[i] = x;\n      else if(fst_max[i] == snd_min[i])\
    \ fst_max[i] = snd_min[i] = x;\n      else fst_max[i] = x;\n    }\n\n    void\
    \ update_node_min(int i, value_type x){\n      sum[i] += (x - fst_min[i]) * min_count[i];\n\
    \n      if(fst_max[i] == fst_min[i]) fst_max[i] = fst_min[i] = x;\n      else\
    \ if(snd_max[i] == fst_min[i]) snd_max[i] = fst_min[i] = x;\n      else fst_min[i]\
    \ = x;\n    }\n\n    void update_node_add(int i, value_type x){\n      const int\
    \ len = hsize >> (31 - __builtin_clz(i));\n\n      sum[i] += x * len;\n      fst_max[i]\
    \ += x;\n      if(snd_max[i] != std::numeric_limits<value_type>::min()) snd_max[i]\
    \ += x;\n      fst_min[i] += x;\n      if(snd_min[i] != std::numeric_limits<value_type>::max())\
    \ snd_min[i] += x;\n\n      lazy_add[i] += x;\n    }\n\n    void propagate(int\
    \ i){\n      if(i >= hsize) return;\n\n      if(lazy_add[i] != 0){\n        update_node_add(lc(i),\
    \ lazy_add[i]);\n        update_node_add(rc(i), lazy_add[i]);\n        lazy_add[i]\
    \ = 0;\n      }\n\n      if(fst_max[i] < fst_max[lc(i)]) update_node_max(lc(i),\
    \ fst_max[i]);\n      if(fst_min[i] > fst_min[lc(i)]) update_node_min(lc(i), fst_min[i]);\n\
    \n      if(fst_max[i] < fst_max[rc(i)]) update_node_max(rc(i), fst_max[i]);\n\
    \      if(fst_min[i] > fst_min[rc(i)]) update_node_min(rc(i), fst_min[i]);\n \
    \   }\n\n    void bottom_up(int i){\n      const int L = lc(i);\n      const int\
    \ R = rc(i);\n\n      sum[i] = sum[L] + sum[R];\n\n      fst_max[i] = std::max(fst_max[L],\
    \ fst_max[R]);\n\n      if(fst_max[L] < fst_max[R]){\n        max_count[i] = max_count[R];\n\
    \        snd_max[i] = std::max(fst_max[L], snd_max[R]);\n      }else if(fst_max[L]\
    \ > fst_max[R]){\n        max_count[i] = max_count[L];\n        snd_max[i] = std::max(snd_max[L],\
    \ fst_max[R]);\n      }else{\n        max_count[i] = max_count[L] + max_count[R];\n\
    \        snd_max[i] = std::max(snd_max[L], snd_max[R]);\n      }\n\n      fst_min[i]\
    \ = std::min(fst_min[L], fst_min[R]);\n\n      if(fst_min[L] > fst_min[R]){\n\
    \        min_count[i] = min_count[R];\n        snd_min[i] = std::min(fst_min[L],\
    \ snd_min[R]);\n      }else if(fst_min[L] < fst_min[R]){\n        min_count[i]\
    \ = min_count[L];\n        snd_min[i] = std::min(snd_min[L], fst_min[R]);\n  \
    \    }else{\n        min_count[i] = min_count[L] + min_count[R];\n        snd_min[i]\
    \ = std::min(snd_min[L], snd_min[R]);\n      }\n    }\n\n  private:\n    void\
    \ chmin(int i, int l, int r, int s, int t, value_type x){\n      if(r <= s or\
    \ t <= l or fst_max[i] <= x) return;\n      if(s <= l and r <= t and snd_max[i]\
    \ < x){\n        update_node_max(i, x);\n        return;\n      }\n\n      propagate(i);\n\
    \      chmin(lc(i), l, (l + r) / 2, s, t, x);\n      chmin(rc(i), (l + r) / 2,\
    \ r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n    void chmin(int l,\
    \ int r, value_type x){chmin(1, 0, hsize, l, r, x);}\n\n  private:\n    void chmax(int\
    \ i, int l, int r, int s, int t, value_type x){\n      if(r <= s or t <= l or\
    \ fst_min[i] >= x) return;\n      if(s <= l and r <= t and snd_min[i] > x){\n\
    \        update_node_min(i, x);\n        return;\n      }\n\n      propagate(i);\n\
    \      chmax(lc(i), l, (l + r) / 2, s, t, x);\n      chmax(rc(i), (l + r) / 2,\
    \ r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n    void chmax(int l,\
    \ int r, value_type x){chmax(1, 0, hsize, l, r, x);}\n\n  private:\n    void add(int\
    \ i, int l, int r, int s, int t, value_type x){\n      if(r <= s or t <= l) return;\n\
    \      if(s <= l and r <= t){\n        update_node_add(i, x);\n        return;\n\
    \      }\n\n      propagate(i);\n      add(lc(i), l, (l + r) / 2, s, t, x);\n\
    \      add(rc(i), (l + r) / 2, r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n\
    \    void add(int l, int r, value_type x){add(1, 0, hsize, l, r, x);}\n\n  private:\n\
    \    value_type get_sum(int i, int l, int r, int s, int t){\n      if(r <= s or\
    \ t <= l) return 0;\n      if(s <= l and r <= t) return sum[i];\n\n      propagate(i);\n\
    \      return get_sum(lc(i), l, (l + r) / 2, s, t) + get_sum(rc(i), (l + r) /\
    \ 2, r, s, t);\n    }\n\n  public:\n    value_type get_sum(int l, int r){return\
    \ get_sum(1, 0, hsize, l, r);}\n\n  public:\n    void init_with_vector(const std::vector<value_type>\
    \ &v){\n      fst_max.assign(size, std::numeric_limits<value_type>::min());\n\
    \      snd_max.assign(size, std::numeric_limits<value_type>::min());\n      max_count.assign(size,\
    \ 1);\n\n      fst_min.assign(size, std::numeric_limits<value_type>::max());\n\
    \      snd_min.assign(size, std::numeric_limits<value_type>::max());\n      min_count.assign(size,\
    \ 1);\n\n      sum.assign(size, 0);\n      lazy_add.assign(size, 0);\n\n     \
    \ for(int i = 0; i < (int)v.size(); ++i){\n        fst_max[hsize + i] = v[i];\n\
    \        max_count[hsize + i] = 1;\n        fst_min[hsize + i] = v[i];\n     \
    \   min_count[hsize + i] = 1;\n        sum[hsize + i] = v[i];\n      }\n\n   \
    \   for(int i = hsize - 1; i > 0; --i) bottom_up(i);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <limits>\n#include <algorithm>\n\
    \nnamespace haar_lib {\n  class segment_tree_beats {\n    using value_type = int64_t;\n\
    \n    const int depth, size, hsize;\n\n    std::vector<value_type> fst_max, snd_max;\n\
    \    std::vector<int> max_count;\n\n    std::vector<value_type> fst_min, snd_min;\n\
    \    std::vector<int> min_count;\n\n    std::vector<value_type> sum, lazy_add;\n\
    \n  public:\n    segment_tree_beats(int n):\n      depth(n > 1 ? 32 - __builtin_clz(n\
    \ - 1) + 1 : 1),\n      size(1 << depth),\n      hsize(size / 2),\n\n      fst_max(size,\
    \ std::numeric_limits<value_type>::min()),\n      snd_max(size, std::numeric_limits<value_type>::min()),\n\
    \      max_count(size, 0),\n\n      fst_min(size, std::numeric_limits<value_type>::max()),\n\
    \      snd_min(size, std::numeric_limits<value_type>::max()),\n      min_count(size,\
    \ 0),\n\n      sum(size, 0),\n      lazy_add(size, 0)\n    {}\n\n  private:\n\
    \    int lc(int i) const {return i << 1 | 0;} // left child\n    int rc(int i)\
    \ const {return i << 1 | 1;} // right child\n\n    void update_node_max(int i,\
    \ value_type x){\n      sum[i] += (x - fst_max[i]) * max_count[i];\n\n      if(fst_max[i]\
    \ == fst_min[i]) fst_max[i] = fst_min[i] = x;\n      else if(fst_max[i] == snd_min[i])\
    \ fst_max[i] = snd_min[i] = x;\n      else fst_max[i] = x;\n    }\n\n    void\
    \ update_node_min(int i, value_type x){\n      sum[i] += (x - fst_min[i]) * min_count[i];\n\
    \n      if(fst_max[i] == fst_min[i]) fst_max[i] = fst_min[i] = x;\n      else\
    \ if(snd_max[i] == fst_min[i]) snd_max[i] = fst_min[i] = x;\n      else fst_min[i]\
    \ = x;\n    }\n\n    void update_node_add(int i, value_type x){\n      const int\
    \ len = hsize >> (31 - __builtin_clz(i));\n\n      sum[i] += x * len;\n      fst_max[i]\
    \ += x;\n      if(snd_max[i] != std::numeric_limits<value_type>::min()) snd_max[i]\
    \ += x;\n      fst_min[i] += x;\n      if(snd_min[i] != std::numeric_limits<value_type>::max())\
    \ snd_min[i] += x;\n\n      lazy_add[i] += x;\n    }\n\n    void propagate(int\
    \ i){\n      if(i >= hsize) return;\n\n      if(lazy_add[i] != 0){\n        update_node_add(lc(i),\
    \ lazy_add[i]);\n        update_node_add(rc(i), lazy_add[i]);\n        lazy_add[i]\
    \ = 0;\n      }\n\n      if(fst_max[i] < fst_max[lc(i)]) update_node_max(lc(i),\
    \ fst_max[i]);\n      if(fst_min[i] > fst_min[lc(i)]) update_node_min(lc(i), fst_min[i]);\n\
    \n      if(fst_max[i] < fst_max[rc(i)]) update_node_max(rc(i), fst_max[i]);\n\
    \      if(fst_min[i] > fst_min[rc(i)]) update_node_min(rc(i), fst_min[i]);\n \
    \   }\n\n    void bottom_up(int i){\n      const int L = lc(i);\n      const int\
    \ R = rc(i);\n\n      sum[i] = sum[L] + sum[R];\n\n      fst_max[i] = std::max(fst_max[L],\
    \ fst_max[R]);\n\n      if(fst_max[L] < fst_max[R]){\n        max_count[i] = max_count[R];\n\
    \        snd_max[i] = std::max(fst_max[L], snd_max[R]);\n      }else if(fst_max[L]\
    \ > fst_max[R]){\n        max_count[i] = max_count[L];\n        snd_max[i] = std::max(snd_max[L],\
    \ fst_max[R]);\n      }else{\n        max_count[i] = max_count[L] + max_count[R];\n\
    \        snd_max[i] = std::max(snd_max[L], snd_max[R]);\n      }\n\n      fst_min[i]\
    \ = std::min(fst_min[L], fst_min[R]);\n\n      if(fst_min[L] > fst_min[R]){\n\
    \        min_count[i] = min_count[R];\n        snd_min[i] = std::min(fst_min[L],\
    \ snd_min[R]);\n      }else if(fst_min[L] < fst_min[R]){\n        min_count[i]\
    \ = min_count[L];\n        snd_min[i] = std::min(snd_min[L], fst_min[R]);\n  \
    \    }else{\n        min_count[i] = min_count[L] + min_count[R];\n        snd_min[i]\
    \ = std::min(snd_min[L], snd_min[R]);\n      }\n    }\n\n  private:\n    void\
    \ chmin(int i, int l, int r, int s, int t, value_type x){\n      if(r <= s or\
    \ t <= l or fst_max[i] <= x) return;\n      if(s <= l and r <= t and snd_max[i]\
    \ < x){\n        update_node_max(i, x);\n        return;\n      }\n\n      propagate(i);\n\
    \      chmin(lc(i), l, (l + r) / 2, s, t, x);\n      chmin(rc(i), (l + r) / 2,\
    \ r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n    void chmin(int l,\
    \ int r, value_type x){chmin(1, 0, hsize, l, r, x);}\n\n  private:\n    void chmax(int\
    \ i, int l, int r, int s, int t, value_type x){\n      if(r <= s or t <= l or\
    \ fst_min[i] >= x) return;\n      if(s <= l and r <= t and snd_min[i] > x){\n\
    \        update_node_min(i, x);\n        return;\n      }\n\n      propagate(i);\n\
    \      chmax(lc(i), l, (l + r) / 2, s, t, x);\n      chmax(rc(i), (l + r) / 2,\
    \ r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n    void chmax(int l,\
    \ int r, value_type x){chmax(1, 0, hsize, l, r, x);}\n\n  private:\n    void add(int\
    \ i, int l, int r, int s, int t, value_type x){\n      if(r <= s or t <= l) return;\n\
    \      if(s <= l and r <= t){\n        update_node_add(i, x);\n        return;\n\
    \      }\n\n      propagate(i);\n      add(lc(i), l, (l + r) / 2, s, t, x);\n\
    \      add(rc(i), (l + r) / 2, r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n\
    \    void add(int l, int r, value_type x){add(1, 0, hsize, l, r, x);}\n\n  private:\n\
    \    value_type get_sum(int i, int l, int r, int s, int t){\n      if(r <= s or\
    \ t <= l) return 0;\n      if(s <= l and r <= t) return sum[i];\n\n      propagate(i);\n\
    \      return get_sum(lc(i), l, (l + r) / 2, s, t) + get_sum(rc(i), (l + r) /\
    \ 2, r, s, t);\n    }\n\n  public:\n    value_type get_sum(int l, int r){return\
    \ get_sum(1, 0, hsize, l, r);}\n\n  public:\n    void init_with_vector(const std::vector<value_type>\
    \ &v){\n      fst_max.assign(size, std::numeric_limits<value_type>::min());\n\
    \      snd_max.assign(size, std::numeric_limits<value_type>::min());\n      max_count.assign(size,\
    \ 1);\n\n      fst_min.assign(size, std::numeric_limits<value_type>::max());\n\
    \      snd_min.assign(size, std::numeric_limits<value_type>::max());\n      min_count.assign(size,\
    \ 1);\n\n      sum.assign(size, 0);\n      lazy_add.assign(size, 0);\n\n     \
    \ for(int i = 0; i < (int)v.size(); ++i){\n        fst_max[hsize + i] = v[i];\n\
    \        max_count[hsize + i] = 1;\n        fst_min[hsize + i] = v[i];\n     \
    \   min_count[hsize + i] = 1;\n        sum[hsize + i] = v[i];\n      }\n\n   \
    \   for(int i = hsize - 1; i > 0; --i) bottom_up(i);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
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

