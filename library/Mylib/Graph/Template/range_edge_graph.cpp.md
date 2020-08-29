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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: Range edge graph

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#d9afcc29a820df9cbf03e35749db39d5">Mylib/Graph/Template</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Template/range_edge_graph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 23:55:47+09:00




## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #406 (Div. 1) B. Legacy](https://codeforces.com/contest/786/problem/B)
- [D - Shortest Path on a Line](https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d)

## References

- [https://ei1333.hateblo.jp/entry/2017/12/14/000000](https://ei1333.hateblo.jp/entry/2017/12/14/000000)
- [https://twitter.com/noshi91/status/1193177214453338113](https://twitter.com/noshi91/status/1193177214453338113)
- [https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)


## Depends on

* :question: <a href="graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>
#include <cassert>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Range edge graph
 * @docs range_edge_graph.md
 */
template <typename T>
class RangeEdgeGraph : public Graph<T>{
  using super = Graph<T>;
  
  int k, N;
  int calc_size(int N) const {
    int ret = 1;
    while(ret < N) ret *= 2;
    return ret;
  }

public:
  RangeEdgeGraph(int N): Graph<T>(5 * (k = (calc_size(N)))), N(N){
    for(int i = 2; i < 2 * k; ++i){
      super::add_edge(k + (i >> 1), k + i, 0);
      super::add_edge(3 * k + i, 3 * k + (i >> 1), 0);
    }

    for(int i = 0; i < N; ++i){
      super::add_edge(2 * k + i, i, 0);
      super::add_edge(i, 4 * k + i, 0);
    }
  }

  void add_edge(int i, int j, T w){
    super::add_edge(i, j, w);
  }

  void add_edge(int i, std::pair<int, int> p, T w){
    auto [l, r] = p;
    for(l += k, r += k; l < r; l >>= 1, r >>= 1){
      if(l & 1) super::add_edge(i, l + k, w), ++l;
      if(r & 1) --r, super::add_edge(i, r + k, w);
    }
  }

  void add_edge(std::pair<int, int> p, int i, T w){
    auto [l, r] = p;
    for(l += k, r += k; l < r; l >>= 1, r >>= 1){
      if(l & 1) super::add_edge(l + 3 * k, i, w), ++l;
      if(r & 1) --r, super::add_edge(r + 3 * k, i, w);
    }
  }

  void add_edge(std::pair<int, int> p, std::pair<int, int> q, T w){
    int x = super::size();
    super::data.emplace_back();
    int y = super::size();
    super::data.emplace_back();

    add_edge(p, x, 0);
    add_edge(x, y, w);
    add_edge(y, q, 0);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Template/range_edge_graph.cpp"
#include <utility>
#include <cassert>
#line 2 "Mylib/Graph/Template/graph.cpp"
#include <vector>

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge{
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph{
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
#line 5 "Mylib/Graph/Template/range_edge_graph.cpp"

/**
 * @title Range edge graph
 * @docs range_edge_graph.md
 */
template <typename T>
class RangeEdgeGraph : public Graph<T>{
  using super = Graph<T>;
  
  int k, N;
  int calc_size(int N) const {
    int ret = 1;
    while(ret < N) ret *= 2;
    return ret;
  }

public:
  RangeEdgeGraph(int N): Graph<T>(5 * (k = (calc_size(N)))), N(N){
    for(int i = 2; i < 2 * k; ++i){
      super::add_edge(k + (i >> 1), k + i, 0);
      super::add_edge(3 * k + i, 3 * k + (i >> 1), 0);
    }

    for(int i = 0; i < N; ++i){
      super::add_edge(2 * k + i, i, 0);
      super::add_edge(i, 4 * k + i, 0);
    }
  }

  void add_edge(int i, int j, T w){
    super::add_edge(i, j, w);
  }

  void add_edge(int i, std::pair<int, int> p, T w){
    auto [l, r] = p;
    for(l += k, r += k; l < r; l >>= 1, r >>= 1){
      if(l & 1) super::add_edge(i, l + k, w), ++l;
      if(r & 1) --r, super::add_edge(i, r + k, w);
    }
  }

  void add_edge(std::pair<int, int> p, int i, T w){
    auto [l, r] = p;
    for(l += k, r += k; l < r; l >>= 1, r >>= 1){
      if(l & 1) super::add_edge(l + 3 * k, i, w), ++l;
      if(r & 1) --r, super::add_edge(r + 3 * k, i, w);
    }
  }

  void add_edge(std::pair<int, int> p, std::pair<int, int> q, T w){
    int x = super::size();
    super::data.emplace_back();
    int y = super::size();
    super::data.emplace_back();

    add_edge(p, x, 0);
    add_edge(x, y, w);
    add_edge(y, q, 0);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

