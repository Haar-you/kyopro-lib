---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/FenwickTree/fenwick_tree.cpp
    title: Fenwick tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp\"\
    \n#include <vector>\n#include <numeric>\n#include <algorithm>\n#line 3 \"Mylib/DataStructure/FenwickTree/fenwick_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename AbelianGroup>\n  class fenwick_tree\
    \ {\n    using value_type = typename AbelianGroup::value_type;\n    const static\
    \ AbelianGroup G;\n\n    int size;\n    std::vector<value_type> data;\n\n  public:\n\
    \    fenwick_tree(){}\n    fenwick_tree(int size):\n      size(size), data(size\
    \ + 1, G())\n    {}\n\n    void update(int i, const value_type &val){\n      i\
    \ += 1; // 1-index\n\n      while(i <= size){\n        data[i] = G(data[i], val);\n\
    \        i += i & (-i);\n      }\n    }\n\n    value_type fold(int i) const {\
    \ // [0, i)\n      value_type ret = G();\n\n      while(i > 0){\n        ret =\
    \ G(ret, data[i]);\n        i -= i & (-i);\n      }\n\n      return ret;\n   \
    \ }\n\n    value_type fold(int l, int r) const { // [l, r)\n      return G(fold(r),\
    \ G.inv(fold(l)));\n    }\n\n    value_type operator[](int x) const {\n      return\
    \ fold(x, x + 1);\n    }\n  };\n}\n#line 6 \"Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename AbelianGroup>\n  class fenwick_tree_on_fenwick_tree\
    \ {\n    using value_type = typename AbelianGroup::value_type;\n    const static\
    \ AbelianGroup G;\n\n    int N = 0;\n    std::vector<int64_t> xs, ys;\n    std::vector<int>\
    \ c_xs;\n\n    std::vector<std::vector<int>> c_ys;\n\n    int x_size;\n\n    std::vector<fenwick_tree<AbelianGroup>>\
    \ segs;\n\n  public:\n    fenwick_tree_on_fenwick_tree(){}\n\n    void add(int64_t\
    \ x, int64_t y){\n      xs.push_back(x);\n      ys.push_back(y);\n      ++N;\n\
    \    }\n\n    void build(){\n      c_xs.insert(c_xs.end(), xs.begin(), xs.end());\n\
    \n      std::sort(c_xs.begin(), c_xs.end());\n      c_xs.erase(std::unique(c_xs.begin(),\
    \ c_xs.end()), c_xs.end());\n\n      x_size = c_xs.size();\n\n      c_ys.resize(x_size\
    \ + 1);\n      segs.resize(x_size + 1);\n\n      std::vector<int> ord(N);\n  \
    \    std::iota(ord.begin(), ord.end(), 0);\n      std::sort(ord.begin(), ord.end(),\
    \ [&](int i, int j){return ys[i] < ys[j];});\n      for(auto i : ord){\n     \
    \   int x = std::lower_bound(c_xs.begin(), c_xs.end(), xs[i]) - c_xs.begin();\n\
    \n        for(x += 1; x <= x_size; x += x & (-x)){\n          c_ys[x].emplace_back(ys[i]);\n\
    \        }\n      }\n\n      for(int i = 1; i <= x_size; ++i){\n        auto &a\
    \ = c_ys[i];\n        a.erase(std::unique(a.begin(), a.end()), a.end());\n\n \
    \       segs[i] = fenwick_tree<AbelianGroup>(c_ys[i].size());\n      }\n    }\n\
    \n    void update(std::pair<int, int> p, const value_type &val){\n      const\
    \ auto [x, y] = p;\n      int i = std::lower_bound(c_xs.begin(), c_xs.end(), x)\
    \ - c_xs.begin();\n\n      for(i += 1; i <= x_size; i += i & (-i)){\n        int\
    \ j = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y) - c_ys[i].begin();\n\
    \        segs[i].update(j, val);\n      }\n    }\n\n  private:\n    value_type\
    \ get(int i, int64_t y1, int64_t y2) const {\n      value_type ret = G();\n  \
    \    for(; i > 0; i -= i & (-i)){\n        int l = std::lower_bound(c_ys[i].begin(),\
    \ c_ys[i].end(), y1) - c_ys[i].begin();\n        int r = std::lower_bound(c_ys[i].begin(),\
    \ c_ys[i].end(), y2) - c_ys[i].begin();\n        ret = G(ret, segs[i].fold(l,\
    \ r));\n      }\n      return ret;\n    }\n\n  public:\n    // [x1, x2), [y1,\
    \ y2)\n    value_type fold(std::pair<int64_t, int64_t> p1, std::pair<int64_t,\
    \ int64_t> p2) const {\n      const auto [x1, y1] = p1;\n      const auto [x2,\
    \ y2] = p2;\n      int l = std::lower_bound(c_xs.begin(), c_xs.end(), x1) - c_xs.begin();\n\
    \      int r = std::lower_bound(c_xs.begin(), c_xs.end(), x2) - c_xs.begin();\n\
    \      return G(get(r, y1, y2), G.inv(get(l, y1, y2)));\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <numeric>\n#include <algorithm>\n\
    #include \"Mylib/DataStructure/FenwickTree/fenwick_tree.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename AbelianGroup>\n  class fenwick_tree_on_fenwick_tree\
    \ {\n    using value_type = typename AbelianGroup::value_type;\n    const static\
    \ AbelianGroup G;\n\n    int N = 0;\n    std::vector<int64_t> xs, ys;\n    std::vector<int>\
    \ c_xs;\n\n    std::vector<std::vector<int>> c_ys;\n\n    int x_size;\n\n    std::vector<fenwick_tree<AbelianGroup>>\
    \ segs;\n\n  public:\n    fenwick_tree_on_fenwick_tree(){}\n\n    void add(int64_t\
    \ x, int64_t y){\n      xs.push_back(x);\n      ys.push_back(y);\n      ++N;\n\
    \    }\n\n    void build(){\n      c_xs.insert(c_xs.end(), xs.begin(), xs.end());\n\
    \n      std::sort(c_xs.begin(), c_xs.end());\n      c_xs.erase(std::unique(c_xs.begin(),\
    \ c_xs.end()), c_xs.end());\n\n      x_size = c_xs.size();\n\n      c_ys.resize(x_size\
    \ + 1);\n      segs.resize(x_size + 1);\n\n      std::vector<int> ord(N);\n  \
    \    std::iota(ord.begin(), ord.end(), 0);\n      std::sort(ord.begin(), ord.end(),\
    \ [&](int i, int j){return ys[i] < ys[j];});\n      for(auto i : ord){\n     \
    \   int x = std::lower_bound(c_xs.begin(), c_xs.end(), xs[i]) - c_xs.begin();\n\
    \n        for(x += 1; x <= x_size; x += x & (-x)){\n          c_ys[x].emplace_back(ys[i]);\n\
    \        }\n      }\n\n      for(int i = 1; i <= x_size; ++i){\n        auto &a\
    \ = c_ys[i];\n        a.erase(std::unique(a.begin(), a.end()), a.end());\n\n \
    \       segs[i] = fenwick_tree<AbelianGroup>(c_ys[i].size());\n      }\n    }\n\
    \n    void update(std::pair<int, int> p, const value_type &val){\n      const\
    \ auto [x, y] = p;\n      int i = std::lower_bound(c_xs.begin(), c_xs.end(), x)\
    \ - c_xs.begin();\n\n      for(i += 1; i <= x_size; i += i & (-i)){\n        int\
    \ j = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y) - c_ys[i].begin();\n\
    \        segs[i].update(j, val);\n      }\n    }\n\n  private:\n    value_type\
    \ get(int i, int64_t y1, int64_t y2) const {\n      value_type ret = G();\n  \
    \    for(; i > 0; i -= i & (-i)){\n        int l = std::lower_bound(c_ys[i].begin(),\
    \ c_ys[i].end(), y1) - c_ys[i].begin();\n        int r = std::lower_bound(c_ys[i].begin(),\
    \ c_ys[i].end(), y2) - c_ys[i].begin();\n        ret = G(ret, segs[i].fold(l,\
    \ r));\n      }\n      return ret;\n    }\n\n  public:\n    // [x1, x2), [y1,\
    \ y2)\n    value_type fold(std::pair<int64_t, int64_t> p1, std::pair<int64_t,\
    \ int64_t> p2) const {\n      const auto [x1, y1] = p1;\n      const auto [x2,\
    \ y2] = p2;\n      int l = std::lower_bound(c_xs.begin(), c_xs.end(), x1) - c_xs.begin();\n\
    \      int r = std::lower_bound(c_xs.begin(), c_xs.end(), x2) - c_xs.begin();\n\
    \      return G(get(r, y1, y2), G.inv(get(l, y1, y2)));\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/DataStructure/FenwickTree/fenwick_tree.cpp
  isVerificationFile: false
  path: Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp
  requiredBy: []
  timestamp: '2020-09-26 08:06:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
documentation_of: Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp
layout: document
title: Fenwick tree (On Fenwick tree)
---

## Operations

## Requirements

## Notes

## Problems

## References
