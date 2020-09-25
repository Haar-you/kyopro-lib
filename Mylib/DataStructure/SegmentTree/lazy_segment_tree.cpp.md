---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_F/main.test.cpp
    title: test/aoj/DSL_2_F/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667/main.test.cpp
    title: test/aoj/2667/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3035/main.test.cpp
    title: test/aoj/3035/main.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_H/main.test.cpp
    title: test/aoj/DSL_2_H/main.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_I/main.test.cpp
    title: test/aoj/DSL_2_I/main.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_G/main.test.cpp
    title: test/aoj/DSL_2_G/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/range_affine_range_sum/main.test.cpp
    title: test/yosupo-judge/range_affine_range_sum/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1099/main.test.cpp
    title: test/yukicoder/1099/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/631/main.test.cpp
    title: test/yukicoder/631/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/899/main.test.cpp
    title: test/yukicoder/899/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename MonoidGet, typename\
    \ MonoidUpdate, template <typename, typename> typename Connector>\n  class lazy_segment_tree\
    \ {\n    using value_type_get = typename MonoidGet::value_type;\n    using value_type_update\
    \ = typename MonoidUpdate::value_type;\n    Connector<MonoidGet, MonoidUpdate>\
    \ M;\n    MonoidGet M_get;\n    MonoidUpdate M_update;\n\n    const int depth,\
    \ size, hsize;\n    std::vector<value_type_get> data;\n    std::vector<value_type_update>\
    \ lazy;\n\n    void propagate(int i){\n      if(lazy[i] == M_update()) return;\n\
    \      if(i < hsize){\n        lazy[i << 1 | 0] = M_update(lazy[i], lazy[i <<\
    \ 1 | 0]);\n        lazy[i << 1 | 1] = M_update(lazy[i], lazy[i << 1 | 1]);\n\
    \      }\n      int len = hsize >> (31 - __builtin_clz(i));\n      data[i] = M(data[i],\
    \ lazy[i], len);\n      lazy[i] = M_update();\n    }\n\n    void propagate_top_down(int\
    \ i){\n      std::vector<int> temp;\n      while(i > 1){\n        i >>= 1;\n \
    \       temp.push_back(i);\n      }\n\n      for(auto it = temp.rbegin(); it !=\
    \ temp.rend(); ++it) propagate(*it);\n    }\n\n    void bottom_up(int i){\n  \
    \    while(i > 1){\n        i >>= 1;\n        propagate(i << 1 | 0);\n       \
    \ propagate(i << 1 | 1);\n        data[i] = M_get(data[i << 1 | 0], data[i <<\
    \ 1 | 1]);\n      }\n    }\n\n  public:\n    lazy_segment_tree(){}\n    lazy_segment_tree(int\
    \ n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 <<\
    \ depth),\n      hsize(size / 2),\n      data(size, M_get()),\n      lazy(size,\
    \ M_update())\n    {}\n\n    void update(int l, int r, const value_type_update\
    \ &x){\n      propagate_top_down(l + hsize);\n      if(r < hsize) propagate_top_down(r\
    \ + hsize);\n\n      int L = l + hsize, R = r + hsize;\n\n      while(L < R){\n\
    \        if(R & 1){\n          --R;\n          lazy[R] = M_update(x, lazy[R]);\n\
    \          propagate(R);\n        }\n        if(L & 1){\n          lazy[L] = M_update(x,\
    \ lazy[L]);\n          propagate(L);\n          ++L;\n        }\n        L >>=\
    \ 1;\n        R >>= 1;\n      }\n\n      bottom_up(l + hsize);\n      if(r < hsize)\
    \ bottom_up(r + hsize);\n    }\n\n    void update(int i, const value_type_update\
    \ &x){update(i, i + 1, x);}\n\n    value_type_get fold(int l, int r){\n      propagate_top_down(l\
    \ + hsize);\n      if(r < hsize) propagate_top_down(r + hsize);\n\n      value_type_get\
    \ ret_left = M_get(), ret_right = M_get();\n\n      int L = l + hsize, R = r +\
    \ hsize;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n        \
    \  propagate(R);\n          ret_right = M_get(data[R], ret_right);\n        }\n\
    \        if(L & 1){\n          propagate(L);\n          ret_left = M_get(ret_left,\
    \ data[L]);\n          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n \
    \     }\n\n      return M_get(ret_left, ret_right);\n    }\n\n    value_type_get\
    \ operator[](int i){return fold(i, i + 1);}\n\n    template <typename T>\n   \
    \ void init(const T &val){\n      init_with_vector(std::vector<T>(hsize, val));\n\
    \    }\n\n    template <typename T>\n    void init_with_vector(const std::vector<T>\
    \ &val){\n      data.assign(size, M_get());\n      lazy.assign(size, M_update());\n\
    \      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = (value_type_get)val[i];\n\
    \      for(int i = hsize - 1; i > 0; --i) data[i] = M_get(data[i << 1 | 0], data[i\
    \ << 1 | 1]);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ MonoidGet, typename MonoidUpdate, template <typename, typename> typename Connector>\n\
    \  class lazy_segment_tree {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n    Connector<MonoidGet,\
    \ MonoidUpdate> M;\n    MonoidGet M_get;\n    MonoidUpdate M_update;\n\n    const\
    \ int depth, size, hsize;\n    std::vector<value_type_get> data;\n    std::vector<value_type_update>\
    \ lazy;\n\n    void propagate(int i){\n      if(lazy[i] == M_update()) return;\n\
    \      if(i < hsize){\n        lazy[i << 1 | 0] = M_update(lazy[i], lazy[i <<\
    \ 1 | 0]);\n        lazy[i << 1 | 1] = M_update(lazy[i], lazy[i << 1 | 1]);\n\
    \      }\n      int len = hsize >> (31 - __builtin_clz(i));\n      data[i] = M(data[i],\
    \ lazy[i], len);\n      lazy[i] = M_update();\n    }\n\n    void propagate_top_down(int\
    \ i){\n      std::vector<int> temp;\n      while(i > 1){\n        i >>= 1;\n \
    \       temp.push_back(i);\n      }\n\n      for(auto it = temp.rbegin(); it !=\
    \ temp.rend(); ++it) propagate(*it);\n    }\n\n    void bottom_up(int i){\n  \
    \    while(i > 1){\n        i >>= 1;\n        propagate(i << 1 | 0);\n       \
    \ propagate(i << 1 | 1);\n        data[i] = M_get(data[i << 1 | 0], data[i <<\
    \ 1 | 1]);\n      }\n    }\n\n  public:\n    lazy_segment_tree(){}\n    lazy_segment_tree(int\
    \ n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 <<\
    \ depth),\n      hsize(size / 2),\n      data(size, M_get()),\n      lazy(size,\
    \ M_update())\n    {}\n\n    void update(int l, int r, const value_type_update\
    \ &x){\n      propagate_top_down(l + hsize);\n      if(r < hsize) propagate_top_down(r\
    \ + hsize);\n\n      int L = l + hsize, R = r + hsize;\n\n      while(L < R){\n\
    \        if(R & 1){\n          --R;\n          lazy[R] = M_update(x, lazy[R]);\n\
    \          propagate(R);\n        }\n        if(L & 1){\n          lazy[L] = M_update(x,\
    \ lazy[L]);\n          propagate(L);\n          ++L;\n        }\n        L >>=\
    \ 1;\n        R >>= 1;\n      }\n\n      bottom_up(l + hsize);\n      if(r < hsize)\
    \ bottom_up(r + hsize);\n    }\n\n    void update(int i, const value_type_update\
    \ &x){update(i, i + 1, x);}\n\n    value_type_get fold(int l, int r){\n      propagate_top_down(l\
    \ + hsize);\n      if(r < hsize) propagate_top_down(r + hsize);\n\n      value_type_get\
    \ ret_left = M_get(), ret_right = M_get();\n\n      int L = l + hsize, R = r +\
    \ hsize;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n        \
    \  propagate(R);\n          ret_right = M_get(data[R], ret_right);\n        }\n\
    \        if(L & 1){\n          propagate(L);\n          ret_left = M_get(ret_left,\
    \ data[L]);\n          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n \
    \     }\n\n      return M_get(ret_left, ret_right);\n    }\n\n    value_type_get\
    \ operator[](int i){return fold(i, i + 1);}\n\n    template <typename T>\n   \
    \ void init(const T &val){\n      init_with_vector(std::vector<T>(hsize, val));\n\
    \    }\n\n    template <typename T>\n    void init_with_vector(const std::vector<T>\
    \ &val){\n      data.assign(size, M_get());\n      lazy.assign(size, M_update());\n\
    \      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = (value_type_get)val[i];\n\
    \      for(int i = hsize - 1; i > 0; --i) data[i] = M_get(data[i << 1 | 0], data[i\
    \ << 1 | 1]);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_2_F/main.test.cpp
  - test/aoj/2667/main.test.cpp
  - test/aoj/3035/main.test.cpp
  - test/aoj/DSL_2_H/main.test.cpp
  - test/aoj/DSL_2_I/main.test.cpp
  - test/aoj/DSL_2_G/main.test.cpp
  - test/yosupo-judge/range_affine_range_sum/main.test.cpp
  - test/yukicoder/1099/main.test.cpp
  - test/yukicoder/631/main.test.cpp
  - test/yukicoder/899/main.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
layout: document
title: Lazy segment tree
---

## Operations

## Requirements

## Notes

## Problems

## References
