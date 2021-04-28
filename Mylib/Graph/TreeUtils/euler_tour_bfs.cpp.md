---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/899/main.test.cpp
    title: test/yukicoder/899/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/euler_tour_bfs.cpp\"\n#include <queue>\n\
    #include <vector>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\
    #line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n    int index\
    \ = -1;\n    edge() {}\n    edge(int from, int to, T cost) : from(from), to(to),\
    \ cost(cost) {}\n    edge(int from, int to, T cost, int index) : from(from), to(to),\
    \ cost(cost), index(index) {}\n  };\n\n  template <typename T>\n  struct graph\
    \ {\n    using weight_type = T;\n    using edge_type   = edge<T>;\n\n    std::vector<std::vector<edge<T>>>\
    \ data;\n\n    auto& operator[](size_t i) { return data[i]; }\n    const auto&\
    \ operator[](size_t i) const { return data[i]; }\n\n    auto begin() const { return\
    \ data.begin(); }\n    auto end() const { return data.end(); }\n\n    graph()\
    \ {}\n    graph(int N) : data(N) {}\n\n    bool empty() const { return data.empty();\
    \ }\n    int size() const { return data.size(); }\n\n    void add_edge(int i,\
    \ int j, T w, int index = -1) {\n      data[i].emplace_back(i, j, w, index);\n\
    \    }\n\n    void add_undirected(int i, int j, T w, int index = -1) {\n     \
    \ add_edge(i, j, w, index);\n      add_edge(j, i, w, index);\n    }\n\n    template\
    \ <size_t I, bool DIRECTED = true, bool WEIGHTED = true>\n    void read(int M)\
    \ {\n      for (int i = 0; i < M; ++i) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n        if (WEIGHTED)\
    \ std::cin >> w;\n        if (DIRECTED)\n          add_edge(u, v, w, i);\n   \
    \     else\n          add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}  // namespace haar_lib\n#line 5 \"\
    Mylib/Graph/TreeUtils/euler_tour_bfs.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  class euler_tour_bfs {\n    int N_;\n    std::vector<int> parent_,\
    \ depth_, left_, right_;\n    std::vector<std::vector<int>> bfs_order_, dfs_order_;\n\
    \n  public:\n    euler_tour_bfs() {}\n    euler_tour_bfs(const tree<T> &tr, int\
    \ root) : N_(tr.size()), parent_(N_), depth_(N_), left_(N_), right_(N_) {\n  \
    \    {\n        int ord = 0;\n        dfs(tr, root, -1, 0, ord);\n      }\n\n\
    \      {\n        std::queue<std::pair<int, int>> q;\n        q.emplace(root,\
    \ 0);\n        int ord = 0;\n\n        while (not q.empty()) {\n          auto\
    \ [i, d] = q.front();\n          q.pop();\n\n          if ((int) bfs_order_.size()\
    \ <= d) bfs_order_.emplace_back();\n          bfs_order_[d].push_back(ord);\n\
    \          ++ord;\n\n          for (auto &e : tr[i]) {\n            if (e.to ==\
    \ parent_[i]) continue;\n            q.emplace(e.to, d + 1);\n          }\n  \
    \      }\n      }\n    }\n\n  private:\n    void dfs(const tree<T> &tr, int cur,\
    \ int par, int d, int &ord) {\n      parent_[cur] = par;\n      depth_[cur]  =\
    \ d;\n\n      if ((int) dfs_order_.size() <= d) dfs_order_.emplace_back();\n \
    \     dfs_order_[d].push_back(ord);\n      left_[cur] = ord;\n      ++ord;\n\n\
    \      for (auto &e : tr[cur]) {\n        if (e.to == par) continue;\n       \
    \ dfs(tr, e.to, cur, d + 1, ord);\n      }\n\n      right_[cur] = ord;\n    }\n\
    \n  public:\n    template <typename Func>\n    void query_children(int i, int\
    \ d, const Func &f) const {\n      if (i != -1) {\n        d += depth_[i];\n \
    \       if ((int) bfs_order_.size() > d) {\n          int l = std::lower_bound(dfs_order_[d].begin(),\
    \ dfs_order_[d].end(), left_[i]) - dfs_order_[d].begin();\n          int r = std::lower_bound(dfs_order_[d].begin(),\
    \ dfs_order_[d].end(), right_[i]) - dfs_order_[d].begin();\n\n          if (l\
    \ >= (int) bfs_order_[d].size()) return;\n          if (r == l) return;\n\n  \
    \        f(bfs_order_[d][l], bfs_order_[d][r - 1] + 1);\n        }\n      }\n\
    \    }\n\n    template <typename Func>\n    void query_at(int i, const Func &f)\
    \ const {\n      query_children(i, 0, f);\n    }\n\n    int get_parent(int i)\
    \ const {\n      if (i == -1) return -1;\n      return parent_[i];\n    }\n\n\
    \    int get_ancestor(int i, int k) const {\n      int ret = i;\n      for (int\
    \ i = 0; i < k; ++i) {\n        ret = get_parent(ret);\n        if (ret == -1)\
    \ break;\n      }\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class euler_tour_bfs {\n\
    \    int N_;\n    std::vector<int> parent_, depth_, left_, right_;\n    std::vector<std::vector<int>>\
    \ bfs_order_, dfs_order_;\n\n  public:\n    euler_tour_bfs() {}\n    euler_tour_bfs(const\
    \ tree<T> &tr, int root) : N_(tr.size()), parent_(N_), depth_(N_), left_(N_),\
    \ right_(N_) {\n      {\n        int ord = 0;\n        dfs(tr, root, -1, 0, ord);\n\
    \      }\n\n      {\n        std::queue<std::pair<int, int>> q;\n        q.emplace(root,\
    \ 0);\n        int ord = 0;\n\n        while (not q.empty()) {\n          auto\
    \ [i, d] = q.front();\n          q.pop();\n\n          if ((int) bfs_order_.size()\
    \ <= d) bfs_order_.emplace_back();\n          bfs_order_[d].push_back(ord);\n\
    \          ++ord;\n\n          for (auto &e : tr[i]) {\n            if (e.to ==\
    \ parent_[i]) continue;\n            q.emplace(e.to, d + 1);\n          }\n  \
    \      }\n      }\n    }\n\n  private:\n    void dfs(const tree<T> &tr, int cur,\
    \ int par, int d, int &ord) {\n      parent_[cur] = par;\n      depth_[cur]  =\
    \ d;\n\n      if ((int) dfs_order_.size() <= d) dfs_order_.emplace_back();\n \
    \     dfs_order_[d].push_back(ord);\n      left_[cur] = ord;\n      ++ord;\n\n\
    \      for (auto &e : tr[cur]) {\n        if (e.to == par) continue;\n       \
    \ dfs(tr, e.to, cur, d + 1, ord);\n      }\n\n      right_[cur] = ord;\n    }\n\
    \n  public:\n    template <typename Func>\n    void query_children(int i, int\
    \ d, const Func &f) const {\n      if (i != -1) {\n        d += depth_[i];\n \
    \       if ((int) bfs_order_.size() > d) {\n          int l = std::lower_bound(dfs_order_[d].begin(),\
    \ dfs_order_[d].end(), left_[i]) - dfs_order_[d].begin();\n          int r = std::lower_bound(dfs_order_[d].begin(),\
    \ dfs_order_[d].end(), right_[i]) - dfs_order_[d].begin();\n\n          if (l\
    \ >= (int) bfs_order_[d].size()) return;\n          if (r == l) return;\n\n  \
    \        f(bfs_order_[d][l], bfs_order_[d][r - 1] + 1);\n        }\n      }\n\
    \    }\n\n    template <typename Func>\n    void query_at(int i, const Func &f)\
    \ const {\n      query_children(i, 0, f);\n    }\n\n    int get_parent(int i)\
    \ const {\n      if (i == -1) return -1;\n      return parent_[i];\n    }\n\n\
    \    int get_ancestor(int i, int k) const {\n      int ret = i;\n      for (int\
    \ i = 0; i < k; ++i) {\n        ret = get_parent(ret);\n        if (ret == -1)\
    \ break;\n      }\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/euler_tour_bfs.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/899/main.test.cpp
documentation_of: Mylib/Graph/TreeUtils/euler_tour_bfs.cpp
layout: document
title: Euler tour (BFS)
---

## Operations

- `EulerTourBFS(tree, int root)`
- `query_children(int i, int d, f)`
	- `i`の`d`個下の子孫に`f`を適用する。
- `query_at(int i, f)`
	- `query_children(i, 0, f)`と同等。
- `get_parent`
	- `i`の親を返す。
- `get_ancestor(int i, int k)`
	- `i`の`k`個遡った祖先を返す。
	- `get_ancestor(i, 0) = i`
	- `get_ancestor(i, 1) = get_parent(i)`
	- Time complexity $O(k)$

## Requirements

## Notes

## Problems

- [yukicoder No.899 γatheree](https://yukicoder.me/problems/no/899)

## References

- [https://niuez.hatenablog.com/entry/2019/10/05/002503](https://niuez.hatenablog.com/entry/2019/10/05/002503)
- [https://niuez.github.io/posts/entry/2019/10/05/002503/](https://niuez.github.io/posts/entry/2019/10/05/002503/)

