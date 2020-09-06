---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: 2-SAT

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#791a56799ce3ef8e4fb5da8cbce3a9bf">Mylib/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/two_sat.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00




## Operations

- `TwoSat(int n)`
- `add_if(int a, int b)`
	- $a \rightarrow b$を導入する。
- `add_or(int a, int b)`
	- $a \lor b$を導入する。
- `not_coexist(int a, int b)`
	- $\lnot (a \land b)$を導入する。
- `solve()`
	- 与えられた論理式をすべて`True`にするような変数の真偽値の割り当てを返す。
	- Time complexity $O(V + E)$

## Requirements

- `add_if`, `add_or`, `not_coexist`の引数は`[1, n]`または`[-n, -1]`を満たさなければならない。
	- 正数`i`は$x_i$を、負数`-i`は$\lnot x_i$を表す。

## Problems

- [yukicoder No.274 The Wall](https://yukicoder.me/problems/no/274)
- [yukicoder No.470 Inverse S+T Problem](https://yukicoder.me/problems/no/470)
- [ARC 069 F - Flags](https://atcoder.jp/contests/arc069/tasks/arc069_d)

## References



## Depends on

* :x: <a href="GraphUtils/strongly_connected_components.cpp.html">Strongly connected components</a>
* :x: <a href="Template/graph.cpp.html">Basic graph</a>
* :x: <a href="TopologicalSort/topological_sort.cpp.html">Topological sort</a>


## Verified with

* :x: <a href="../../../verify/test/yosupo-judge/two_sat/main.test.cpp.html">test/yosupo-judge/two_sat/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <cassert>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include "Mylib/Graph/TopologicalSort/topological_sort.cpp"

/**
 * @title 2-SAT
 * @docs two_sat.md
 */
class TwoSat {
  const int n;
  Graph<int> g;

  int f(int i){
    assert(i != 0);
    assert(abs(i) <= n);
    if(i > 0) return i - 1;
    else return abs(i) - 1 + n;
  }

public:
  TwoSat(int n): n(n), g(2 * n){}

  /**
   * @note a→bを導入する
   */
  void add_if(int a, int b){
    g.add_edge(f(a), f(b), 1);
  }

  /**
   * @note a∨bを導入する
   * @note a ∨ b <=> (!a => b) ∧ (!b => a)
   */
  void add_or(int a, int b){
    add_if(-a, b);
    add_if(-b, a);
  }

  /**
   * @note ¬(a∧b)を導入する
   * @note !(A ∧ B) <=> (!A ∨ !B)
   */
  void not_coexist(int a, int b){
    add_or(-a, -b);
  }

public:
  std::optional<std::vector<bool>> solve() const {
    auto [scc, m] = strongly_connected_components(g);

    for(int i = 0; i < n; ++i){
      if(scc[i] == scc[i + n]) return {};
    }

    Graph<int> g2(m);

    for(int i = 0; i < 2 * n; ++i){
      for(auto &e : g[i]){
        if(scc[e.from] != scc[e.to]){
          g2.add_edge(scc[e.from], scc[e.to], 1);
        }
      }
    }

    auto ts = *topological_sort(g2);

    std::vector<int> r(m);
    for(int i = 0; i < m; ++i) r[ts[i]] = i;

    std::vector<bool> ret(n);
    for(int i = 0; i < n; ++i) ret[i] = r[scc[i]] > r[scc[i + n]];

    return {ret};
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/two_sat.cpp"
#include <vector>
#include <optional>
#include <cassert>
#line 3 "Mylib/Graph/Template/graph.cpp"
#include <iostream>

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge {
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph {
  using weight_type = T;
  using edge_type = Edge<T>;

  std::vector<std::vector<Edge<T>>> data;

  auto& operator[](size_t i){return data[i];}
  const auto& operator[](size_t i) const {return data[i];}

  auto begin() const {return data.begin();}
  auto end() const {return data.end();}

  Graph(){}
  Graph(int N): data(N){}

  bool empty() const {return data.empty();}
  int size() const {return data.size();}

  void add_edge(int i, int j, T w, int index = -1){
    data[i].emplace_back(i, j, w, index);
  }

  void add_undirected(int i, int j, T w, int index = -1){
    add_edge(i, j, w, index);
    add_edge(j, i, w, index);
  }

  template <size_t I, bool DIRECTED = true, bool WEIGHTED = true>
  void read(int M){
    for(int i = 0; i < M; ++i){
      int u, v; std::cin >> u >> v;
      u -= I;
      v -= I;
      T w = 1;
      if(WEIGHTED) std::cin >> w;
      if(DIRECTED) add_edge(u, v, w, i);
      else add_undirected(u, v, w, i);
    }
  }
};

template <typename T>
using Tree = Graph<T>;
#line 3 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include <algorithm>
#line 5 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

/**
 * @title Strongly connected components
 * @docs strongly_connected_components.md
 */
template <typename T>
auto strongly_connected_components(const Graph<T> &g){
  const int n = g.size();

  std::vector<bool> visit(n);
  std::vector<int> check(n);
  std::vector<int> result(n, -1);

  auto dfs =
    [&](auto &f, int cur) -> void {
      visit[cur] = true;
      for(const auto &e : g[cur]){
        if(not visit[e.to]) f(f, e.to);
      }
      check.push_back(cur);
    };

  for(int i = 0; i < n; ++i) if(not visit[i]) dfs(dfs, i);

  std::reverse(check.begin(), check.end());

  Graph<T> rg(n);

  auto rdfs =
    [&](auto &f, int cur, int i) -> void {
      result[cur] = i;
      for(const auto &e : rg[cur]){
        if(result[e.to] == -1) f(f, e.to, i);
      }
    };

  for(int i = 0; i < n; ++i) for(const auto &e : g[i]) rg[e.to].emplace_back(e.to, e.from, e.cost);

  int i = 0;
  for(auto c : check) if(result[c] == -1) rdfs(rdfs, c, i), ++i;

  return std::make_pair(result, i);
}
#line 4 "Mylib/Graph/TopologicalSort/topological_sort.cpp"
#include <queue>
#line 6 "Mylib/Graph/TopologicalSort/topological_sort.cpp"

/**
 * @title Topological sort
 * @docs topological_sort.md
 */
template <typename T>
std::optional<std::vector<int>> topological_sort(const Graph<T> &g){
  const int n = g.size();
  std::vector<int> indeg(n);

  for(int i = 0; i < n; ++i){
    for(auto &e : g[i]){
      ++indeg[e.to];
    }
  }

  std::queue<int> q;
  for(int i = 0; i < n; ++i){
    if(indeg[i] == 0) q.push(i);
  }

  std::vector<int> ret;
  while(not q.empty()){
    int cur = q.front(); q.pop();
    ret.push_back(cur);
    for(auto &e : g[cur]){
      --indeg[e.to];
      if(indeg[e.to] == 0){
        q.push(e.to);
      }
    }
  }

  if((int)ret.size() == n){
    return {ret};
  }else{
    return std::nullopt;
  }
}
#line 8 "Mylib/Graph/two_sat.cpp"

/**
 * @title 2-SAT
 * @docs two_sat.md
 */
class TwoSat {
  const int n;
  Graph<int> g;

  int f(int i){
    assert(i != 0);
    assert(abs(i) <= n);
    if(i > 0) return i - 1;
    else return abs(i) - 1 + n;
  }

public:
  TwoSat(int n): n(n), g(2 * n){}

  /**
   * @note a→bを導入する
   */
  void add_if(int a, int b){
    g.add_edge(f(a), f(b), 1);
  }

  /**
   * @note a∨bを導入する
   * @note a ∨ b <=> (!a => b) ∧ (!b => a)
   */
  void add_or(int a, int b){
    add_if(-a, b);
    add_if(-b, a);
  }

  /**
   * @note ¬(a∧b)を導入する
   * @note !(A ∧ B) <=> (!A ∨ !B)
   */
  void not_coexist(int a, int b){
    add_or(-a, -b);
  }

public:
  std::optional<std::vector<bool>> solve() const {
    auto [scc, m] = strongly_connected_components(g);

    for(int i = 0; i < n; ++i){
      if(scc[i] == scc[i + n]) return {};
    }

    Graph<int> g2(m);

    for(int i = 0; i < 2 * n; ++i){
      for(auto &e : g[i]){
        if(scc[e.from] != scc[e.to]){
          g2.add_edge(scc[e.from], scc[e.to], 1);
        }
      }
    }

    auto ts = *topological_sort(g2);

    std::vector<int> r(m);
    for(int i = 0; i < m; ++i) r[ts[i]] = i;

    std::vector<bool> ret(n);
    for(int i = 0; i < n; ++i) ret[i] = r[scc[i]] > r[scc[i + n]];

    return {ret};
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

