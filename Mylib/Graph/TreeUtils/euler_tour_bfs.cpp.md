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
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/euler_tour_bfs.cpp\"\n#include <vector>\n\
    #include <queue>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct edge {\n    int from,\
    \ to;\n    T cost;\n    int index = -1;\n    edge(){}\n    edge(int from, int\
    \ to, T cost): from(from), to(to), cost(cost){}\n    edge(int from, int to, T\
    \ cost, int index): from(from), to(to), cost(cost), index(index){}\n  };\n\n \
    \ template <typename T>\n  struct graph {\n    using weight_type = T;\n    using\
    \ edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n    auto&\
    \ operator[](size_t i){return data[i];}\n    const auto& operator[](size_t i)\
    \ const {return data[i];}\n\n    auto begin() const {return data.begin();}\n \
    \   auto end() const {return data.end();}\n\n    graph(){}\n    graph(int N):\
    \ data(N){}\n\n    bool empty() const {return data.empty();}\n    int size() const\
    \ {return data.size();}\n\n    void add_edge(int i, int j, T w, int index = -1){\n\
    \      data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1){\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M){\n      for(int i = 0; i < M; ++i){\n        int\
    \ u, v; std::cin >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n\
    \        if(WEIGHTED) std::cin >> w;\n        if(DIRECTED) add_edge(u, v, w, i);\n\
    \        else add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Graph/TreeUtils/euler_tour_bfs.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct euler_tour_bfs {\n\
    \    int N;\n    std::vector<int> parent;\n    std::vector<int> depth;\n\n   \
    \ std::vector<std::vector<int>> bfs_order;\n    std::vector<std::vector<int>>\
    \ dfs_order;\n    std::vector<int> left, right;\n\n    euler_tour_bfs(const tree<T>\
    \ &tr, int root):\n      N(tr.size()), parent(N), depth(N), left(N), right(N)\n\
    \    {\n      {\n        int ord = 0;\n        dfs(tr, root, -1, 0, ord);\n  \
    \    }\n\n      {\n        std::queue<std::pair<int, int>> q;\n        q.emplace(root,\
    \ 0);\n        int ord = 0;\n\n        while(not q.empty()){\n          auto [i,\
    \ d] = q.front(); q.pop();\n\n          if((int)bfs_order.size() <= d) bfs_order.emplace_back();\n\
    \          bfs_order[d].push_back(ord);\n          ++ord;\n\n          for(auto\
    \ &e : tr[i]){\n            if(e.to == parent[i]) continue;\n            q.emplace(e.to,\
    \ d + 1);\n          }\n        }\n      }\n    }\n\n    void dfs(const tree<T>\
    \ &tr, int cur, int par, int d, int &ord){\n      parent[cur] = par;\n      depth[cur]\
    \ = d;\n\n      if((int)dfs_order.size() <= d) dfs_order.emplace_back();\n   \
    \   dfs_order[d].push_back(ord);\n      left[cur] = ord;\n      ++ord;\n\n   \
    \   for(auto &e : tr[cur]){\n        if(e.to == par) continue;\n        dfs(tr,\
    \ e.to, cur, d + 1, ord);\n      }\n\n      right[cur] = ord;\n    }\n\n  public:\n\
    \    template <typename Func>\n    void query_children(int i, int d, const Func\
    \ &f) const {\n      if(i != -1){\n        d += depth[i];\n        if((int)bfs_order.size()\
    \ > d){\n          int l = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(),\
    \ left[i]) - dfs_order[d].begin();\n          int r = std::lower_bound(dfs_order[d].begin(),\
    \ dfs_order[d].end(), right[i]) - dfs_order[d].begin();\n\n          if(l >= (int)bfs_order[d].size())\
    \ return;\n          if(r == l) return;\n\n          f(bfs_order[d][l], bfs_order[d][r\
    \ - 1] + 1);\n        }\n      }\n    }\n\n    template <typename Func>\n    void\
    \ query_at(int i, const Func &f) const {\n      query_children(i, 0, f);\n   \
    \ }\n\n    int get_parent(int i) const {\n      if(i == -1) return -1;\n     \
    \ return parent[i];\n    }\n\n    int get_ancestor(int i, int k) const {\n   \
    \   int ret = i;\n      for(int i = 0; i < k; ++i){\n        ret = get_parent(ret);\n\
    \        if(ret == -1) break;\n      }\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct euler_tour_bfs {\n\
    \    int N;\n    std::vector<int> parent;\n    std::vector<int> depth;\n\n   \
    \ std::vector<std::vector<int>> bfs_order;\n    std::vector<std::vector<int>>\
    \ dfs_order;\n    std::vector<int> left, right;\n\n    euler_tour_bfs(const tree<T>\
    \ &tr, int root):\n      N(tr.size()), parent(N), depth(N), left(N), right(N)\n\
    \    {\n      {\n        int ord = 0;\n        dfs(tr, root, -1, 0, ord);\n  \
    \    }\n\n      {\n        std::queue<std::pair<int, int>> q;\n        q.emplace(root,\
    \ 0);\n        int ord = 0;\n\n        while(not q.empty()){\n          auto [i,\
    \ d] = q.front(); q.pop();\n\n          if((int)bfs_order.size() <= d) bfs_order.emplace_back();\n\
    \          bfs_order[d].push_back(ord);\n          ++ord;\n\n          for(auto\
    \ &e : tr[i]){\n            if(e.to == parent[i]) continue;\n            q.emplace(e.to,\
    \ d + 1);\n          }\n        }\n      }\n    }\n\n    void dfs(const tree<T>\
    \ &tr, int cur, int par, int d, int &ord){\n      parent[cur] = par;\n      depth[cur]\
    \ = d;\n\n      if((int)dfs_order.size() <= d) dfs_order.emplace_back();\n   \
    \   dfs_order[d].push_back(ord);\n      left[cur] = ord;\n      ++ord;\n\n   \
    \   for(auto &e : tr[cur]){\n        if(e.to == par) continue;\n        dfs(tr,\
    \ e.to, cur, d + 1, ord);\n      }\n\n      right[cur] = ord;\n    }\n\n  public:\n\
    \    template <typename Func>\n    void query_children(int i, int d, const Func\
    \ &f) const {\n      if(i != -1){\n        d += depth[i];\n        if((int)bfs_order.size()\
    \ > d){\n          int l = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(),\
    \ left[i]) - dfs_order[d].begin();\n          int r = std::lower_bound(dfs_order[d].begin(),\
    \ dfs_order[d].end(), right[i]) - dfs_order[d].begin();\n\n          if(l >= (int)bfs_order[d].size())\
    \ return;\n          if(r == l) return;\n\n          f(bfs_order[d][l], bfs_order[d][r\
    \ - 1] + 1);\n        }\n      }\n    }\n\n    template <typename Func>\n    void\
    \ query_at(int i, const Func &f) const {\n      query_children(i, 0, f);\n   \
    \ }\n\n    int get_parent(int i) const {\n      if(i == -1) return -1;\n     \
    \ return parent[i];\n    }\n\n    int get_ancestor(int i, int k) const {\n   \
    \   int ret = i;\n      for(int i = 0; i < k; ++i){\n        ret = get_parent(ret);\n\
    \        if(ret == -1) break;\n      }\n      return ret;\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/euler_tour_bfs.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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

