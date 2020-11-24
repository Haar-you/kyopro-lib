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
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/vertex_add_path_sum/main.test.cpp
    title: test/yosupo-judge/vertex_add_path_sum/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
    title: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
    title: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1030/main.test.cpp
    title: test/yukicoder/1030/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235/main.test.cpp
    title: test/yukicoder/235/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
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
    \    int n_;\n\n    std::vector<int> sub_, // subtree size\n      par_, // parent\
    \ id\n      head_, // chain head id\n      id_, // id[original id] = hld id\n\
    \      rid_, // rid[hld id] = original id\n      next_, // next node in a chain\n\
    \      end_; //\n\n    int dfs_sub(tree<T> &tr, int cur, int p){\n      par_[cur]\
    \ = p;\n      int t = 0;\n      for(auto &e : tr[cur]){\n        if(e.to == p)\
    \ continue;\n        sub_[cur] += dfs_sub(tr, e.to, cur);\n        if(sub_[e.to]\
    \ > t){\n          t = sub_[e.to];\n          next_[cur] = e.to;\n          std::swap(e,\
    \ tr[cur][0]);\n        }\n      }\n      return sub_[cur];\n    }\n\n    void\
    \ dfs_build(const tree<T> &tr, int cur, int &i){\n      id_[cur] = i;\n      rid_[i]\
    \ = cur;\n      ++i;\n\n      for(auto &e : tr[cur]){\n        if(e.to == par_[cur])\
    \ continue;\n        head_[e.to] = (e.to == tr[cur][0].to ? head_[cur] : e.to);\n\
    \        dfs_build(tr, e.to, i);\n      }\n\n      end_[cur] = i;\n    }\n\n \
    \ public:\n    hl_decomposition(){}\n    hl_decomposition(tree<T> tr, int root):\n\
    \      n_(tr.size()), sub_(n_, 1), par_(n_, -1), head_(n_), id_(n_), rid_(n_),\
    \ next_(n_, -1), end_(n_, -1){\n      dfs_sub(tr, root, -1);\n      int i = 0;\n\
    \      dfs_build(tr, root, i);\n    }\n\n    std::vector<std::tuple<int, int,\
    \ bool>> path_query_vertex(int x, int y) const {\n      std::vector<std::tuple<int,\
    \ int, bool>> ret;\n      const int w = lca(x, y);\n\n      {\n        int y =\
    \ w;\n        bool d = true;\n        while(1){\n          if(id_[x] > id_[y])\
    \ std::swap(x, y), d = not d;\n          int l = std::max(id_[head_[y]], id_[x]),\
    \ r = id_[y] + 1;\n          if(l != r) ret.emplace_back(l, r, d);\n         \
    \ if(head_[x] == head_[y]) break;\n          y = par_[head_[y]];\n        }\n\
    \      }\n\n      x = y;\n      y = w;\n\n      {\n        std::vector<std::tuple<int,\
    \ int, bool>> temp;\n        bool d = false;\n        while(1){\n          if(id_[x]\
    \ > id_[y]) std::swap(x, y), d = not d;\n          int l = std::max({id_[head_[y]],\
    \ id_[x], id_[w] + 1}), r = id_[y] + 1;\n          if(l != r) temp.emplace_back(l,\
    \ r, d);\n          if(head_[x] == head_[y]) break;\n          y = par_[head_[y]];\n\
    \        }\n\n        std::reverse(temp.begin(), temp.end());\n        ret.insert(ret.end(),\
    \ temp.begin(), temp.end());\n      }\n\n      return ret;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> path_query_edge(int x, int y) const {\n      std::vector<std::pair<int,\
    \ int>> ret;\n      while(1){\n        if(id_[x] > id_[y]) std::swap(x, y);\n\
    \        if(head_[x] == head_[y]){\n          if(x != y) ret.emplace_back(id_[x]\
    \ + 1, id_[y] + 1);\n          break;\n        }\n        ret.emplace_back(id_[head_[y]],\
    \ id_[y] + 1);\n        y = par_[head_[y]];\n      }\n      return ret;\n    }\n\
    \n    std::pair<int, int> subtree_query_edge(int x) const {\n      return {id_[x]\
    \ + 1, end_[x]};\n    }\n\n    std::pair<int, int> subtree_query_vertex(int x)\
    \ const {\n      return {id_[x], end_[x]};\n    }\n\n    int get_edge_id(int u,\
    \ int v) const { // \u8FBA\u306B\u5BFE\u5FDC\u3059\u308Bid\n      if(par_[u] ==\
    \ v) return id_[u];\n      if(par_[v] == u) return id_[v];\n      return -1;\n\
    \    }\n\n    int parent(int x) const {return par_[x];};\n\n    int lca(int u,\
    \ int v) const {\n      while(1){\n        if(id_[u] > id_[v]) std::swap(u, v);\n\
    \        if(head_[u] == head_[v]) return u;\n        v = par_[head_[v]];\n   \
    \   }\n    }\n\n    int get_id(int x) const {\n      return id_[x];\n    }\n \
    \ };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  class hl_decomposition {\n    int n_;\n\n    std::vector<int>\
    \ sub_, // subtree size\n      par_, // parent id\n      head_, // chain head\
    \ id\n      id_, // id[original id] = hld id\n      rid_, // rid[hld id] = original\
    \ id\n      next_, // next node in a chain\n      end_; //\n\n    int dfs_sub(tree<T>\
    \ &tr, int cur, int p){\n      par_[cur] = p;\n      int t = 0;\n      for(auto\
    \ &e : tr[cur]){\n        if(e.to == p) continue;\n        sub_[cur] += dfs_sub(tr,\
    \ e.to, cur);\n        if(sub_[e.to] > t){\n          t = sub_[e.to];\n      \
    \    next_[cur] = e.to;\n          std::swap(e, tr[cur][0]);\n        }\n    \
    \  }\n      return sub_[cur];\n    }\n\n    void dfs_build(const tree<T> &tr,\
    \ int cur, int &i){\n      id_[cur] = i;\n      rid_[i] = cur;\n      ++i;\n\n\
    \      for(auto &e : tr[cur]){\n        if(e.to == par_[cur]) continue;\n    \
    \    head_[e.to] = (e.to == tr[cur][0].to ? head_[cur] : e.to);\n        dfs_build(tr,\
    \ e.to, i);\n      }\n\n      end_[cur] = i;\n    }\n\n  public:\n    hl_decomposition(){}\n\
    \    hl_decomposition(tree<T> tr, int root):\n      n_(tr.size()), sub_(n_, 1),\
    \ par_(n_, -1), head_(n_), id_(n_), rid_(n_), next_(n_, -1), end_(n_, -1){\n \
    \     dfs_sub(tr, root, -1);\n      int i = 0;\n      dfs_build(tr, root, i);\n\
    \    }\n\n    std::vector<std::tuple<int, int, bool>> path_query_vertex(int x,\
    \ int y) const {\n      std::vector<std::tuple<int, int, bool>> ret;\n      const\
    \ int w = lca(x, y);\n\n      {\n        int y = w;\n        bool d = true;\n\
    \        while(1){\n          if(id_[x] > id_[y]) std::swap(x, y), d = not d;\n\
    \          int l = std::max(id_[head_[y]], id_[x]), r = id_[y] + 1;\n        \
    \  if(l != r) ret.emplace_back(l, r, d);\n          if(head_[x] == head_[y]) break;\n\
    \          y = par_[head_[y]];\n        }\n      }\n\n      x = y;\n      y =\
    \ w;\n\n      {\n        std::vector<std::tuple<int, int, bool>> temp;\n     \
    \   bool d = false;\n        while(1){\n          if(id_[x] > id_[y]) std::swap(x,\
    \ y), d = not d;\n          int l = std::max({id_[head_[y]], id_[x], id_[w] +\
    \ 1}), r = id_[y] + 1;\n          if(l != r) temp.emplace_back(l, r, d);\n   \
    \       if(head_[x] == head_[y]) break;\n          y = par_[head_[y]];\n     \
    \   }\n\n        std::reverse(temp.begin(), temp.end());\n        ret.insert(ret.end(),\
    \ temp.begin(), temp.end());\n      }\n\n      return ret;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> path_query_edge(int x, int y) const {\n      std::vector<std::pair<int,\
    \ int>> ret;\n      while(1){\n        if(id_[x] > id_[y]) std::swap(x, y);\n\
    \        if(head_[x] == head_[y]){\n          if(x != y) ret.emplace_back(id_[x]\
    \ + 1, id_[y] + 1);\n          break;\n        }\n        ret.emplace_back(id_[head_[y]],\
    \ id_[y] + 1);\n        y = par_[head_[y]];\n      }\n      return ret;\n    }\n\
    \n    std::pair<int, int> subtree_query_edge(int x) const {\n      return {id_[x]\
    \ + 1, end_[x]};\n    }\n\n    std::pair<int, int> subtree_query_vertex(int x)\
    \ const {\n      return {id_[x], end_[x]};\n    }\n\n    int get_edge_id(int u,\
    \ int v) const { // \u8FBA\u306B\u5BFE\u5FDC\u3059\u308Bid\n      if(par_[u] ==\
    \ v) return id_[u];\n      if(par_[v] == u) return id_[v];\n      return -1;\n\
    \    }\n\n    int parent(int x) const {return par_[x];};\n\n    int lca(int u,\
    \ int v) const {\n      while(1){\n        if(id_[u] > id_[v]) std::swap(u, v);\n\
    \        if(head_[u] == head_[v]) return u;\n        v = par_[head_[v]];\n   \
    \   }\n    }\n\n    int get_id(int x) const {\n      return id_[x];\n    }\n \
    \ };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
  - test/yosupo-judge/vertex_set_path_composite/main.test.cpp
  - test/yosupo-judge/vertex_add_path_sum/main.test.cpp
  - test/yukicoder/235/main.test.cpp
  - test/yukicoder/1030/main.test.cpp
  - test/aoj/2667/main.test.cpp
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

