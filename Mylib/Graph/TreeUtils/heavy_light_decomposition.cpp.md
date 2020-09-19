---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667/main.test.cpp
    title: test/aoj/2667/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
    title: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
    title: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/vertex_add_path_sum/main.test.cpp
    title: test/yosupo-judge/vertex_add_path_sum/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1030/main.test.cpp
    title: test/yukicoder/1030/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235/main.test.cpp
    title: test/yukicoder/235/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\n\
    #include <vector>\n#include <utility>\n#include <algorithm>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
    \n#include <iostream>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ edge {\n    int from, to;\n    T cost;\n    int index = -1;\n    edge(){}\n\
    \    edge(int from, int to, T cost): from(from), to(to), cost(cost){}\n    edge(int\
    \ from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}\n\
    \  };\n\n  template <typename T>\n  struct graph {\n    using weight_type = T;\n\
    \    using edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\
    \n    auto& operator[](size_t i){return data[i];}\n    const auto& operator[](size_t\
    \ i) const {return data[i];}\n\n    auto begin() const {return data.begin();}\n\
    \    auto end() const {return data.end();}\n\n    graph(){}\n    graph(int N):\
    \ data(N){}\n\n    bool empty() const {return data.empty();}\n    int size() const\
    \ {return data.size();}\n\n    void add_edge(int i, int j, T w, int index = -1){\n\
    \      data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1){\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M){\n      for(int i = 0; i < M; ++i){\n        int\
    \ u, v; std::cin >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n\
    \        if(WEIGHTED) std::cin >> w;\n        if(DIRECTED) add_edge(u, v, w, i);\n\
    \        else add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 6 \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class hl_decomposition {\n\
    \    int n;\n\n    std::vector<int> sub, // subtree size\n      par, // parent\
    \ id\n      head, // chain head id\n      id, // id[original id] = hld id\n  \
    \    rid, // rid[hld id] = original id\n      next, // next node in a chain\n\
    \      end; //\n\n    int dfs_sub(tree<T> &tr, int cur, int p){\n      par[cur]\
    \ = p;\n      int t = 0;\n      for(auto &e : tr[cur]){\n        if(e.to == p)\
    \ continue;\n        sub[cur] += dfs_sub(tr, e.to, cur);\n        if(sub[e.to]\
    \ > t){\n          t = sub[e.to];\n          next[cur] = e.to;\n          std::swap(e,\
    \ tr[cur][0]);\n        }\n      }\n      return sub[cur];\n    }\n\n    void\
    \ dfs_build(const tree<T> &tr, int cur, int &i){\n      id[cur] = i;\n      rid[i]\
    \ = cur;\n      ++i;\n\n      for(auto &e : tr[cur]){\n        if(e.to == par[cur])\
    \ continue;\n        head[e.to] = (e.to == tr[cur][0].to ? head[cur] : e.to);\n\
    \        dfs_build(tr, e.to, i);\n      }\n\n      end[cur] = i;\n    }\n\n  public:\n\
    \    hl_decomposition(tree<T> tr, int root):\n      n(tr.size()), sub(n, 1), par(n,\
    \ -1), head(n), id(n), rid(n), next(n, -1), end(n, -1){\n      dfs_sub(tr, root,\
    \ -1);\n      int i = 0;\n      dfs_build(tr, root, i);\n    }\n\n    std::vector<std::tuple<int,\
    \ int, bool>> path_query_vertex(int x, int y) const {\n      std::vector<std::tuple<int,\
    \ int, bool>> ret;\n      const int w = lca(x, y);\n\n      {\n        int y =\
    \ w;\n        bool d = true;\n        while(1){\n          if(id[x] > id[y]) std::swap(x,\
    \ y), d = not d;\n          int l = std::max(id[head[y]], id[x]), r = id[y] +\
    \ 1;\n          if(l != r) ret.emplace_back(l, r, d);\n          if(head[x] ==\
    \ head[y]) break;\n          y = par[head[y]];\n        }\n      }\n\n      x\
    \ = y;\n      y = w;\n\n      {\n        std::vector<std::tuple<int, int, bool>>\
    \ temp;\n        bool d = false;\n        while(1){\n          if(id[x] > id[y])\
    \ std::swap(x, y), d = not d;\n          int l = std::max({id[head[y]], id[x],\
    \ id[w] + 1}), r = id[y] + 1;\n          if(l != r) temp.emplace_back(l, r, d);\n\
    \          if(head[x] == head[y]) break;\n          y = par[head[y]];\n      \
    \  }\n\n        std::reverse(temp.begin(), temp.end());\n        ret.insert(ret.end(),\
    \ temp.begin(), temp.end());\n      }\n\n      return ret;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> path_query_edge(int x, int y) const {\n      std::vector<std::pair<int,\
    \ int>> ret;\n      while(1){\n        if(id[x] > id[y]) std::swap(x, y);\n  \
    \      if(head[x] == head[y]){\n          if(x != y) ret.emplace_back(id[x] +\
    \ 1, id[y] + 1);\n          break;\n        }\n        ret.emplace_back(id[head[y]],\
    \ id[y] + 1);\n        y = par[head[y]];\n      }\n      return ret;\n    }\n\n\
    \    std::pair<int, int> subtree_query_edge(int x) const {\n      return {id[x]\
    \ + 1, end[x]};\n    }\n\n    std::pair<int, int> subtree_query_vertex(int x)\
    \ const {\n      return {id[x], end[x]};\n    }\n\n    int get_edge_id(int u,\
    \ int v) const { // \u8FBA\u306B\u5BFE\u5FDC\u3059\u308Bid\n      if(par[u] ==\
    \ v) return id[u];\n      if(par[v] == u) return id[v];\n      return -1;\n  \
    \  }\n\n    int parent(int x) const {return par[x];};\n\n    int lca(int u, int\
    \ v) const {\n      while(1){\n        if(id[u] > id[v]) std::swap(u, v);\n  \
    \      if(head[u] == head[v]) return u;\n        v = par[head[v]];\n      }\n\
    \    }\n\n    int get_id(int x) const {\n      return id[x];\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  class hl_decomposition {\n    int n;\n\n    std::vector<int>\
    \ sub, // subtree size\n      par, // parent id\n      head, // chain head id\n\
    \      id, // id[original id] = hld id\n      rid, // rid[hld id] = original id\n\
    \      next, // next node in a chain\n      end; //\n\n    int dfs_sub(tree<T>\
    \ &tr, int cur, int p){\n      par[cur] = p;\n      int t = 0;\n      for(auto\
    \ &e : tr[cur]){\n        if(e.to == p) continue;\n        sub[cur] += dfs_sub(tr,\
    \ e.to, cur);\n        if(sub[e.to] > t){\n          t = sub[e.to];\n        \
    \  next[cur] = e.to;\n          std::swap(e, tr[cur][0]);\n        }\n      }\n\
    \      return sub[cur];\n    }\n\n    void dfs_build(const tree<T> &tr, int cur,\
    \ int &i){\n      id[cur] = i;\n      rid[i] = cur;\n      ++i;\n\n      for(auto\
    \ &e : tr[cur]){\n        if(e.to == par[cur]) continue;\n        head[e.to] =\
    \ (e.to == tr[cur][0].to ? head[cur] : e.to);\n        dfs_build(tr, e.to, i);\n\
    \      }\n\n      end[cur] = i;\n    }\n\n  public:\n    hl_decomposition(tree<T>\
    \ tr, int root):\n      n(tr.size()), sub(n, 1), par(n, -1), head(n), id(n), rid(n),\
    \ next(n, -1), end(n, -1){\n      dfs_sub(tr, root, -1);\n      int i = 0;\n \
    \     dfs_build(tr, root, i);\n    }\n\n    std::vector<std::tuple<int, int, bool>>\
    \ path_query_vertex(int x, int y) const {\n      std::vector<std::tuple<int, int,\
    \ bool>> ret;\n      const int w = lca(x, y);\n\n      {\n        int y = w;\n\
    \        bool d = true;\n        while(1){\n          if(id[x] > id[y]) std::swap(x,\
    \ y), d = not d;\n          int l = std::max(id[head[y]], id[x]), r = id[y] +\
    \ 1;\n          if(l != r) ret.emplace_back(l, r, d);\n          if(head[x] ==\
    \ head[y]) break;\n          y = par[head[y]];\n        }\n      }\n\n      x\
    \ = y;\n      y = w;\n\n      {\n        std::vector<std::tuple<int, int, bool>>\
    \ temp;\n        bool d = false;\n        while(1){\n          if(id[x] > id[y])\
    \ std::swap(x, y), d = not d;\n          int l = std::max({id[head[y]], id[x],\
    \ id[w] + 1}), r = id[y] + 1;\n          if(l != r) temp.emplace_back(l, r, d);\n\
    \          if(head[x] == head[y]) break;\n          y = par[head[y]];\n      \
    \  }\n\n        std::reverse(temp.begin(), temp.end());\n        ret.insert(ret.end(),\
    \ temp.begin(), temp.end());\n      }\n\n      return ret;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> path_query_edge(int x, int y) const {\n      std::vector<std::pair<int,\
    \ int>> ret;\n      while(1){\n        if(id[x] > id[y]) std::swap(x, y);\n  \
    \      if(head[x] == head[y]){\n          if(x != y) ret.emplace_back(id[x] +\
    \ 1, id[y] + 1);\n          break;\n        }\n        ret.emplace_back(id[head[y]],\
    \ id[y] + 1);\n        y = par[head[y]];\n      }\n      return ret;\n    }\n\n\
    \    std::pair<int, int> subtree_query_edge(int x) const {\n      return {id[x]\
    \ + 1, end[x]};\n    }\n\n    std::pair<int, int> subtree_query_vertex(int x)\
    \ const {\n      return {id[x], end[x]};\n    }\n\n    int get_edge_id(int u,\
    \ int v) const { // \u8FBA\u306B\u5BFE\u5FDC\u3059\u308Bid\n      if(par[u] ==\
    \ v) return id[u];\n      if(par[v] == u) return id[v];\n      return -1;\n  \
    \  }\n\n    int parent(int x) const {return par[x];};\n\n    int lca(int u, int\
    \ v) const {\n      while(1){\n        if(id[u] > id[v]) std::swap(u, v);\n  \
    \      if(head[u] == head[v]) return u;\n        v = par[head[v]];\n      }\n\
    \    }\n\n    int get_id(int x) const {\n      return id[x];\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2667/main.test.cpp
  - test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
  - test/yosupo-judge/vertex_set_path_composite/main.test.cpp
  - test/yosupo-judge/vertex_add_path_sum/main.test.cpp
  - test/yukicoder/1030/main.test.cpp
  - test/yukicoder/235/main.test.cpp
documentation_of: Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
layout: document
title: Heavy-light decomposition
---

## Operations

- `HLDecomposition(tree, root)`
- `path_query_vertex(int x, int y, f)`
	- `x`, `y`間のパス上の頂点に`f`を適用する。
- `path_query_vertex(int x, int y, f, g)`
- `path_query_edge(int x, int y, f)`
	- `x`, `y`間のパス上の辺に`f`を適用する。
- `subtree_query_vertext(int x, f)`
	- `x`の部分木の頂点に`f`を適用する。
- `subtree_query_edge(int x, f)`
	- `x`の部分木の辺に`f`を適用する。
- `get_edge_id(int u, int v)`
	- 辺`(u, v)`に対応するidを返す。
- `parent(int x)`
	- `x`の親を返す。
- `lca(int u, int v)`
	- `u`と`v`の最小共通祖先を返す。
- `get_id(int x)`
	- 頂点`x`に対応する`id[x]`を返す。

## Requirements

## Notes

## Problems

- [yukicoder No.399 動的な領主](https://yukicoder.me/problems/no/399) (パスに対する頂点クエリ)
- [AOJ 2667 Tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667) (パス・部分木に対する辺クエリ)
- [Codeforces Round #329 (Div. 2) D. Happy Tree Party](https://codeforces.com/contest/593/problem/D) (パスに対する辺クエリ)
- [yukicoder No.650 行列木クエリ](https://yukicoder.me/problems/no/650) (パスに対する辺クエリ)
- [Codeforces Round #200 (Div. 1) D. Water Tree](https://codeforces.com/contest/343/problem/D) (パス・部分木に対する頂点クエリ)

## References

- [https://math314.hateblo.jp/entry/2014/06/24/220107](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [https://beet-aizu.hatenablog.com/entry/2017/12/12/235950](https://beet-aizu.hatenablog.com/entry/2017/12/12/235950)
- [https://www.hamayanhamayan.com/entry/2017/04/10/172636](https://www.hamayanhamayan.com/entry/2017/04/10/172636)

